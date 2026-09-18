const fs=require('fs'),path=require('path');
const root=path.resolve(__dirname, '..');
const walk=d=>fs.readdirSync(d,{withFileTypes:true}).flatMap(e=>e.name==='build'?[]:e.isDirectory()?walk(path.join(d,e.name)):[path.join(d,e.name)]);
const mdFiles=walk(root).filter(f=>f.endsWith('.md'));
const escape=s=>s.replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/>/g,'&gt;').replace(/"/g,'&quot;');
function target(href,file){
 if(/^(https?:|#)/.test(href))return href;
 const resolved=path.resolve(path.dirname(file),decodeURIComponent(href));
 return resolved.startsWith(root+path.sep)&&fs.existsSync(resolved)&&href.endsWith('.md')?href.slice(0,-3)+'.html':href;
}
function inline(text,file){
 let result=escape(text);
 result=result.replace(/\[([^\]]+)\]\(([^)]+)\)/g,(_,label,href)=>'<a href="'+target(href,file)+'">'+label+'</a>');
 result=result.replace(/\x60([^\x60]+)\x60/g,'<code>$1</code>').replace(/\*\*([^*]+)\*\*/g,'<strong>$1</strong>');
 return result;
}
function render(text,file){
 const lines=text.replace(/<details>\s*<summary>(.*?)<\/summary>/g,'<details>\n<summary>$1</summary>').split(/\r?\n/);let out=[],fence=false,code=[],list=false,table=false;
 const close=()=>{if(list){out.push('</ul>');list=false;}if(table){out.push('</tbody></table></div>');table=false;}};
 for(const line of lines){
  if(line.startsWith(String.fromCharCode(96).repeat(3))){
   close();if(fence){out.push('<pre><code>'+escape(code.join('\n'))+'</code></pre>');code=[];}fence=!fence;continue;
  }
  if(fence){code.push(line);continue;}
  if(!line.trim()){close();continue;}
  if(line.trim()==="<details>"||line.trim()==="</details>"){close();out.push(line.trim());continue;}
  const summary=line.trim().match(/^<summary>(.*)<\/summary>$/);
  if(summary){close();out.push("<summary>"+inline(summary[1],file)+"</summary>");continue;}
  if(line.startsWith('|')){
   if(/^\|[\s:|-]+\|$/.test(line))continue;
   const cells=line.split('|').slice(1,-1);
   if(!table){if(list){out.push('</ul>');list=false;}out.push('<div class="table"><table><thead><tr>'+cells.map(s=>'<th>'+inline(s.trim(),file)+'</th>').join('')+'</tr></thead><tbody>');table=true;}
   else out.push('<tr>'+cells.map(s=>'<td>'+inline(s.trim(),file)+'</td>').join('')+'</tr>');
   continue;
  }
  if(table){out.push('</tbody></table></div>');table=false;}
  const heading=line.match(/^(#{1,6})\s+(.*)$/);
  if(heading){close();const level=heading[1].length;out.push('<h'+level+'>'+inline(heading[2],file)+'</h'+level+'>');continue;}
  const bullet=line.match(/^(?:-|\d+\.)\s+(.*)$/);
  if(bullet){if(!list){out.push('<ul>');list=true;}out.push('<li>'+inline(bullet[1],file).replace(/^\[ \] /,'<span class="box" aria-label="未完成">☐</span> ')+'</li>');continue;}
  close();out.push('<p>'+inline(line,file)+'</p>');
 }
 close();return out.join('\n');
}
for(const file of mdFiles){
 const text=fs.readFileSync(file,'utf8'),title=(text.match(/^# (.+)/m)||[])[1]||'练习说明';
 const home=path.relative(path.dirname(file),path.join(root,'index.html')).split(path.sep).join('/');
 const html='<!doctype html><html lang="zh-CN"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>'+escape(title)+'</title><style>'+
 'body{font:16px/1.8 system-ui,"Microsoft YaHei",sans-serif;background:#f5f8f8;color:#182a35;margin:0}main{max-width:1000px;margin:30px auto;padding:30px;background:white;border:1px solid #dce5e8;border-radius:12px}a{color:#087f73;text-underline-offset:4px}nav{border-bottom:1px solid #dce5e8;padding-bottom:16px;color:#607580;font-size:14px}h1{font-size:30px;line-height:1.35}h2{margin-top:32px;font-size:22px}pre{background:#17343b;color:#e0f4ed;padding:18px;overflow:auto;border-radius:8px;line-height:1.6}code{font-family:Consolas,monospace}p code,li code{background:#edf2f3;padding:1px 5px}th,td{border-bottom:1px solid #dce5e8;text-align:left;padding:10px;vertical-align:top}table{border-collapse:collapse;width:100%}.table{overflow:auto}.box{color:#087f73}li{margin:8px 0}footer{font-size:13px;color:#607580;margin-top:30px}details{border:1px solid #dce5e8;border-radius:8px;padding:10px 14px;margin:16px 0}summary{cursor:pointer;font-weight:600}details[open]>summary{margin-bottom:12px}a:focus-visible,summary:focus-visible{outline:3px solid #ffa64c}@media(max-width:700px){main{margin:0;padding:22px 16px;border:0;border-radius:0}h1{font-size:26px}pre{font-size:13px}}'+
 '</style></head><body><main><nav><a href="'+home+'">← 练习导航</a> · <a href="'+path.basename(file)+'">Markdown 原文件</a></nav>'+render(text,file)+'<footer>本页由同目录 Markdown 生成。更新笔记时以 Markdown 为源；页面上的方框用于阅读，实际进度请记在学习记录或导航页。</footer></main></body></html>';
 const destination=file.slice(0,-3)+'.html';
 if(!destination.startsWith(root+path.sep))throw new Error('Unsafe output');
 fs.writeFileSync(destination,html,'utf8');
}
const indexPath=path.join(root,'index.html');
let index=fs.readFileSync(indexPath,'utf8');
index=index.replace(/href="([^"]+)\.md"/g,'href="$1.html"').replace('link("问题与自测",t.problemPath)','link("问题与自测",t.problemPath.replace(/\\.md$/, ".html"))').replace('问题页与代码文件可在 VS Code 中阅读；浏览器可能下载它们。','问题页可直接浏览；C++ 框架请在 VS Code 中编辑，浏览器可能下载代码文件。');
fs.writeFileSync(indexPath,index,'utf8');
console.log('Generated '+mdFiles.length+' readable HTML document pages.');

