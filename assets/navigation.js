
"use strict";
const P=window.PracticeProgress;
const chapters=JSON.parse(document.getElementById("curriculum").textContent);
const tasks=chapters.flatMap(c=>c.tasks.map(t=>({...t,chapter:c.dir}))),ids=tasks.map(t=>t.id),byId=new Map(tasks.map(t=>[t.id,t]));
const key="data-structures-practice-v2",legacyKey="data-structures-practice-v1";
const $=id=>document.getElementById(id);
let records=Object.create(null),pendingImport=null;
function notice(message,error=false){$("save-message").textContent=message;$("save-message").classList.toggle("error",error);}
try{
 const existing=localStorage.getItem(key);
 if(existing){records=P.parseBackup(existing,ids).records;}
 else{
  const legacy=localStorage.getItem(legacyKey);
  if(legacy&&Object.values(JSON.parse(legacy)).some(v=>v===true)){
   const selected=Object.fromEntries(Object.entries(JSON.parse(legacy)).filter(([,v])=>v===true));
   records=P.parseBackup(JSON.stringify(selected),ids).records;
   localStorage.setItem(key,JSON.stringify({schemaVersion:2,records}));
   notice("已保留旧版的手动自测记录。迁移不会认定你已掌握，也没有删除旧备份。");
  }
 }
}catch(error){notice("无法读取或迁移浏览器记录："+error.message+" 可使用导出备份。",true);}
function persist(){
 try{localStorage.setItem(key,JSON.stringify({schemaVersion:2,updatedAt:new Date().toISOString(),records}));notice("已保存在当前浏览器。换设备或清理浏览器前，请导出备份。");}
 catch(error){notice("浏览器未能保存记录。请立即导出备份，避免关闭页面后丢失。",true);}
}
function el(tag,text,cls){const n=document.createElement(tag);if(text!==undefined)n.textContent=text;if(cls)n.className=cls;return n;}
function link(label,href){const a=el("a",label);a.href=href.replace(/\.md(?=#|$)/,".html");if(/^https?:/.test(href)){a.target="_blank";a.rel="noopener noreferrer";}return a;}
function filters(){return {query:$("search").value,chapter:$("chapter").value,level:$("level").value,mode:$("mode").value,material:$("material").value,status:$("status-filter").value};}
function progress(){
 $("stats").replaceChildren();
 for(const row of P.counts(tasks,records)){
  const div=el("div",undefined,"stat");div.append(el("span",row.level),el("strong",row.verified+" / "+row.total),el("small","已核对 · 独立统计"));$("stats").append(div);
 }
}
function render(){
 const matched=P.filtered(tasks,filters(),records);
 const container=$("content");container.replaceChildren();
 for(const chapter of chapters){
  const list=matched.filter(t=>t.chapter===chapter.dir);if(!list.length)continue;
  const section=el("section"),heading=el("div",undefined,"section-heading");
  heading.append(el("h2",chapter.title),el("span",list.length+" 项"));section.append(heading,el("p",chapter.route,"route"));
  const grid=el("div",undefined,"cards");
  for(const task of list){
   const card=el("article");card.id=task.id;card.tabIndex=-1;
   const top=el("div",undefined,"card-meta");top.append(el("span",task.id,"task-id"),el("span",task.level,"tag "+({"基础":"basic","进阶":"advanced","扩展":"extra"}[task.level])),el("span",task.mode,"tag neutral"));
   card.append(top,el("h3",task.title),el("p",task.goal,"goal"));
   const material=el("p",task.material+" · "+task.sourceScope,"material");card.append(material);
   if(task.prerequisites?.length){
    const pre=el("div",undefined,"prerequisites");pre.append(el("span","先会这些："));
    for(const id of task.prerequisites){const target=byId.get(id);if(target)pre.append(link(id+" "+target.title,"#"+id));}
    card.append(pre);
   }
   const actions=el("div",undefined,"actions");actions.append(link(task.mode==="编码"?"题目与自测":"讲解与任务",task.problemPath));
   if(task.codePath)actions.append(link("C++ 框架",task.codePath));
   if(task.reference&&task.reference!==task.problemPath)actions.append(link("对应资料",task.reference));
   if(task.url)actions.append(link("在线题（需核对接口）",task.url));
   card.append(actions);
   const controls=el("div",undefined,"learning");const stateLabel=el("label","我的状态");
   const select=el("select");select.setAttribute("aria-label",task.id+" 学习状态");
   for(const status of P.STATUSES){const op=el("option",P.labels[status]);op.value=status;select.append(op);}
   select.value=records[task.id]?.status||"not-started";stateLabel.append(select);controls.append(stateLabel);
   const notes=el("details");notes.append(el("summary","记录卡点 / 验证证据"));
   const textarea=el("textarea");textarea.rows=3;textarea.maxLength=6000;textarea.value=records[task.id]?.note||"";textarea.placeholder="例如：已通过空表和满表测试；仍不理解删除时的指针顺序。";textarea.setAttribute("aria-label",task.id+" 学习笔记");notes.append(textarea);controls.append(notes);
   const save=()=>{records[task.id]={status:select.value,note:textarea.value,updatedAt:new Date().toISOString()};persist();progress();card.classList.toggle("verified",select.value==="verified");};
   select.addEventListener("change",()=>{save();if($("status-filter").value)render();});textarea.addEventListener("change",save);
   card.classList.toggle("verified",select.value==="verified");card.append(controls);grid.append(card);
  }
  section.append(grid);container.append(section);
 }
 if(!matched.length)container.append(el("p","没有匹配的条目。可以清除筛选，或搜索算法的另一个名称。","empty"));
 $("count").textContent="当前显示 "+matched.length+" / "+tasks.length+" 项；"+tasks.filter(t=>t.codePath).length+" 项有代码框架";
 progress();
}
for(const chapter of chapters){const op=el("option",chapter.title);op.value=chapter.dir;$("chapter").append(op);}
for(const status of P.STATUSES){const op=el("option",P.labels[status]);op.value=status;$("status-filter").append(op);}
for(const id of ["search","chapter","level","mode","material","status-filter"])$(id).addEventListener(id==="search"?"input":"change",render);
$("reset").addEventListener("click",()=>{for(const id of ["search","chapter","level","mode","material","status-filter"])$(id).value="";render();});
function showHash(){
 const id=decodeURIComponent(location.hash.slice(1));if(!byId.has(id))return;
 for(const name of ["search","chapter","level","mode","material","status-filter"])$(name).value="";
 render();const card=document.getElementById(id);card.scrollIntoView({block:"center"});card.focus({preventScroll:true});
}
window.addEventListener("hashchange",showHash);
function download(name,content,type){
 const url=URL.createObjectURL(new Blob([content],{type})),a=el("a");a.href=url;a.download=name;a.click();setTimeout(()=>URL.revokeObjectURL(url),1000);
}
$("export-json").addEventListener("click",()=>{
 download("practice-progress.json",JSON.stringify({schemaVersion:2,exportedAt:new Date().toISOString(),records},null,2),"application/json;charset=utf-8");
 notice("已生成 JSON 备份下载，可在另一浏览器使用“导入记录”恢复。");
});
$("export-md").addEventListener("click",()=>{
 const lines=["# 数据结构与算法学习记录","","手动记录不等于已掌握。",""];
 for(const task of tasks){const record=records[task.id];lines.push("- ["+(record?.status==="verified"?"x":" ")+"] "+task.id+" "+task.title+" — "+P.labels[record?.status||"not-started"]);if(record?.note)lines.push("  笔记："+record.note.replace(/\r?\n/g," / "));}
 download("practice-progress.md",lines.join("\n")+"\n","text/markdown;charset=utf-8");
});
$("import-button").addEventListener("click",()=>$("import-file").click());
$("import-file").addEventListener("change",async event=>{
 const file=event.target.files[0];event.target.value="";if(!file)return;
 try{
  if(file.size>1024*1024)throw new Error("文件超过 1 MB，请选择本练习页导出的记录。");
  pendingImport=P.parseBackup(await file.text(),ids);
  const overlap=Object.keys(pendingImport.records).filter(id=>records[id]).length;
  $("import-summary").textContent="识别到 "+Object.keys(pendingImport.records).length+" 条记录，与本地重叠 "+overlap+" 条；忽略不属于本目录的 "+pendingImport.unknown+" 条。确认前不会改动当前记录。";
  $("overwrite").checked=false;$("import-dialog").showModal();
 }catch(error){pendingImport=null;notice(error.message,true);}
});
$("cancel-import").addEventListener("click",()=>{pendingImport=null;$("import-dialog").close();});
$("apply-import").addEventListener("click",()=>{
 if(!pendingImport)return;
 records=P.mergeRecords(records,pendingImport.records,$("overwrite").checked);pendingImport=null;persist();render();$("import-dialog").close();
});
render();showHash();
