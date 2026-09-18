[CmdletBinding()]
param(
    [string[]]$Ids = @(),
    [ValidateRange(1,300)][int]$TimeoutSeconds = 10,
    [switch]$SelfTest
)
$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$build = Join-Path $root 'build\checks'
[IO.Directory]::CreateDirectory($build) | Out-Null
$encoding = [Text.UTF8Encoding]::new($false)
$devShell = 'D:\Visual Studio2026\Common7\Tools\Launch-VsDevShell.ps1'
if (-not (Test-Path -LiteralPath $devShell -PathType Leaf)) {
    throw 'MSVC environment not found. Update devShell in tools/check_practice.ps1.'
}
& $devShell -SkipAutomaticLocation -Arch amd64 -HostArch amd64 | Out-Null
$compiler = (Get-Command cl.exe -ErrorAction Stop).Source
function Invoke-CapturedProcess {
    param([string]$Program,[string[]]$Arguments,[string]$Directory,[int]$LimitSeconds)
    $start = [Diagnostics.ProcessStartInfo]::new()
    $start.FileName = $Program
    $start.WorkingDirectory = $Directory
    # All arguments are created locally; embedded quotes are escaped for Windows argv.
    $start.Arguments = (($Arguments | ForEach-Object { '"' + $_.Replace('"','\"') + '"' }) -join ' ')
    $start.UseShellExecute = $false
    $start.CreateNoWindow = $true
    $start.RedirectStandardOutput = $true
    $start.RedirectStandardError = $true
    $start.StandardOutputEncoding = [Text.UTF8Encoding]::new($false)
    $start.StandardErrorEncoding = [Text.UTF8Encoding]::new($false)
    $start.EnvironmentVariables['VSLANG'] = '1033'
    $process = [Diagnostics.Process]::new()
    $process.StartInfo = $start
    [void]$process.Start()
    $stdoutTask = $process.StandardOutput.ReadToEndAsync()
    $stderrTask = $process.StandardError.ReadToEndAsync()
    $finished = $process.WaitForExit($LimitSeconds * 1000)
    if (-not $finished) {
        $process.Kill()
        $process.WaitForExit()
    }
    $stdout = $stdoutTask.GetAwaiter().GetResult()
    $stderr = $stderrTask.GetAwaiter().GetResult()
    $exitCode = $process.ExitCode
    $process.Dispose()
    return [pscustomobject]@{ exitCode=$exitCode; timedOut=(-not $finished); stdout=$stdout; stderr=$stderr }
}
$results = [Collections.Generic.List[object]]::new()
$sources = @(Get-ChildItem -LiteralPath $root -Directory |
    Where-Object { $_.Name -match '^\d\d-' } |
    ForEach-Object {
        $code = Join-Path $_.FullName 'code'
        if (Test-Path -LiteralPath $code -PathType Container) { Get-ChildItem -LiteralPath $code -Filter '*.cpp' -File }
    } | Sort-Object FullName)
$requested = @($Ids | ForEach-Object { $_ -split ',' } | ForEach-Object { $_.Trim().ToUpperInvariant() } | Where-Object { $_ })
if ($requested.Count -gt 0) {
    foreach ($id in $requested) {
        if (-not ($sources | Where-Object { $_.BaseName.ToUpperInvariant() -eq $id })) { throw "Unknown exercise id: $id" }
    }
    $sources = @($sources | Where-Object { $_.BaseName.ToUpperInvariant() -in $requested })
}
if ($SelfTest) {
    $helperSource = @'
#include "../../templates/test_support.hpp"
int main(int argc, char** argv) {
    const std::string mode = argc > 1 ? argv[1] : "pass";
    return practice_test::run([&] {
        if (mode == "empty") return;
        if (mode == "timeout") { for (;;) {} }
        if (mode == "todo") todo("self-test");
        if (mode == "exception") throw std::runtime_error("ordinary exception");
        practice_test::equal(std::vector<int>({1,2}),std::vector<int>({1,2}),"vector equality");
        practice_test::require(mode != "fail","deliberate failure");
    });
}
'@
    $helperPath = Join-Path $build 'helper_self_test.cpp'
    [IO.File]::WriteAllText($helperPath,$helperSource,$encoding)
    $helperExe = Join-Path $build 'helper_self_test.exe'
    $helperCompile = Invoke-CapturedProcess $compiler @('/nologo','/std:c++17','/W4','/permissive-','/EHsc','/utf-8',("/Fo"+(Join-Path $build 'helper_self_test.obj')),("/Fe"+$helperExe),$helperPath) $build 60
    if ($helperCompile.exitCode -ne 0 -or $helperCompile.timedOut) {
        throw ("Test infrastructure compilation failed: " + $helperCompile.stdout + $helperCompile.stderr)
    }
    foreach ($mode in @('pass','fail','todo','exception','empty')) {
        $expected = @{pass=0;fail=1;todo=2;exception=1;empty=1}[$mode]
        $probe = Invoke-CapturedProcess $helperExe @($mode) $build $TimeoutSeconds
        if ($probe.timedOut -or $probe.exitCode -ne $expected) { throw "Test infrastructure failed for mode $mode" }
        Write-Host "INFRASTRUCTURE $mode -> $expected (expected)"
    }
    $timeoutProbe = Invoke-CapturedProcess $helperExe @('timeout') $build 1
    if (-not $timeoutProbe.timedOut) { throw 'Test infrastructure timeout failed' }
    Write-Host 'INFRASTRUCTURE timeout -> interrupted (expected)'
}
foreach ($source in $sources) {
    $relative = $source.FullName.Substring($root.Length+1)
    $id = $source.BaseName.ToUpperInvariant()
    $directory = Join-Path $build ([IO.Path]::GetDirectoryName($relative))
    [IO.Directory]::CreateDirectory($directory) | Out-Null
    $stem = Join-Path $directory $source.BaseName
    $compile = Invoke-CapturedProcess $compiler @('/nologo','/std:c++17','/W4','/permissive-','/EHsc','/utf-8','/Od',("/Fo"+$stem+'.obj'),("/Fe"+$stem+'.exe'),$source.FullName) $directory 60
    $compileLog = $compile.stdout + $compile.stderr
    [IO.File]::WriteAllText($stem+'.compile.log',$compileLog,$encoding)
    $record = [ordered]@{
        id=$id; source=$relative; status='compile-failed'; compileExitCode=$compile.exitCode
        warningCount=([regex]::Matches($compileLog,'(?im)(?:warning|\u8b66\u544a)\s+C\d+')).Count
        runExitCode=$null; timedOut=$compile.timedOut; stdout=''; stderr=''
        compileLog=($stem+'.compile.log').Substring($root.Length+1)
    }
    if (-not $compile.timedOut -and $compile.exitCode -eq 0) {
        $run = Invoke-CapturedProcess ($stem+'.exe') @() $directory $TimeoutSeconds
        $record.runExitCode = $run.exitCode
        $record.timedOut = $run.timedOut
        $record.stdout = $run.stdout.Trim()
        $record.stderr = $run.stderr.Trim()
        if ($run.timedOut) { $record.status = 'failed' }
        elseif ($run.exitCode -eq 2 -and ($run.stdout+$run.stderr) -match 'TODO: implement ') { $record.status = 'pending' }
        elseif ($run.exitCode -eq 0 -and $run.stdout -match 'PASS:\s+[1-9]\d* checks') { $record.status = 'passed' }
        else { $record.status = 'failed' }
    }
    $results.Add([pscustomobject]$record)
    Write-Host ($id + ' ' + $record.status)
    if ($record.status -eq 'compile-failed') { Write-Host $compileLog }
    elseif ($record.status -eq 'failed') { Write-Host ($record.stdout + [Environment]::NewLine + $record.stderr) }
}
$summary = [ordered]@{
    generatedAt=(Get-Date).ToString('o'); total=$results.Count
    passed=@($results | Where-Object status -eq 'passed').Count
    pending=@($results | Where-Object status -eq 'pending').Count
    failed=@($results | Where-Object status -eq 'failed').Count
    compileFailed=@($results | Where-Object status -eq 'compile-failed').Count
    warnings=($results | Measure-Object -Property warningCount -Sum).Sum
    selfTestExecuted=[bool]$SelfTest
}
$report = [ordered]@{ summary=$summary; results=@($results.ToArray()) }
$reportPath = Join-Path $build 'latest-results.json'
[IO.File]::WriteAllText($reportPath,($report | ConvertTo-Json -Depth 8),$encoding)
$summary | ConvertTo-Json -Compress | Write-Output
Write-Output ("Report: " + $reportPath)
if ($summary.failed -gt 0 -or $summary.compileFailed -gt 0) { exit 1 }
if ($summary.pending -gt 0) { exit 2 }
exit 0
