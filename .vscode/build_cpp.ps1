param (
    [Parameter(Mandatory = $true)]
    [string]$SourceFile
)

$ErrorActionPreference = 'Stop'
$workspacePath = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$workspacePrefix = $workspacePath.TrimEnd('\') + '\'
$sourcePath = (Resolve-Path -LiteralPath $SourceFile).Path
if (-not $sourcePath.StartsWith($workspacePrefix, [System.StringComparison]::OrdinalIgnoreCase)) {
    throw 'The active source must be inside this data structures practice folder.'
}
if ([System.IO.Path]::GetExtension($sourcePath) -notin @('.cpp', '.cc', '.cxx')) {
    throw 'Select and save a C++ source file before building.'
}

# Keep all generated files in build, mirroring the source subdirectory.
$relativeSource = $sourcePath.Substring($workspacePrefix.Length)
$relativeDirectory = [System.IO.Path]::GetDirectoryName($relativeSource)
$buildRoot = [System.IO.Path]::GetFullPath((Join-Path $workspacePath 'build'))
$outputDirectory = [System.IO.Path]::GetFullPath((Join-Path $buildRoot $relativeDirectory))
if (($outputDirectory -ne $buildRoot) -and
    (-not $outputDirectory.StartsWith($buildRoot + '\', [System.StringComparison]::OrdinalIgnoreCase))) {
    throw 'Unexpected build output directory.'
}
New-Item -ItemType Directory -Path $outputDirectory -Force | Out-Null
$baseName = [System.IO.Path]::GetFileNameWithoutExtension($sourcePath)
$outputStem = Join-Path $outputDirectory $baseName

# Initialize MSVC in this process without changing global PATH.
$devShellPath = 'D:\Visual Studio2026\Common7\Tools\Launch-VsDevShell.ps1'
if (-not (Test-Path -LiteralPath $devShellPath -PathType Leaf)) {
    throw 'MSVC tools were moved. Update devShellPath in .vscode/build_cpp.ps1.'
}
& $devShellPath -SkipAutomaticLocation -Arch amd64 -HostArch amd64 | Out-Null
$compilerPath = (Get-Command cl.exe -ErrorAction Stop).Source

# Debug information and no optimization make stepping easier to follow.
$compilerArguments = @(
    '/nologo', '/std:c++17', '/W4', '/permissive-', '/EHsc', '/utf-8', '/Zi', '/Od',
    "/Fo$outputStem.obj", "/Fd$outputStem.compiler.pdb", "/Fe$outputStem.exe",
    $sourcePath, '/link', '/DEBUG', '/INCREMENTAL:NO', "/PDB:$outputStem.pdb"
)
Push-Location -LiteralPath $outputDirectory
try {
    & $compilerPath @compilerArguments
    $compilerExitCode = $LASTEXITCODE
}
finally {
    Pop-Location
}
if ($compilerExitCode -ne 0) {
    exit $compilerExitCode
}
Write-Output "Built: $outputStem.exe"
exit 0

