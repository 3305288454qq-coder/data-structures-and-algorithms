
(function(scope){
"use strict";
const STATUSES=["not-started","in-progress","blocked","verified","review"];
const labels={"not-started":"未开始","in-progress":"进行中","blocked":"卡住了","verified":"已核对","review":"待复习"};
function plain(value){return value!==null&&typeof value==="object"&&!Array.isArray(value);}
function normalRecord(value){
 if(value===true)return {status:"verified",note:"从旧版手动自测勾选迁移；未重新验证。",updatedAt:""};
 if(!plain(value)||!STATUSES.includes(value.status))return null;
 if(value.note!==undefined&&typeof value.note!=="string")return null;
 return {status:value.status,note:(value.note||"").slice(0,6000),updatedAt:typeof value.updatedAt==="string"?value.updatedAt.slice(0,40):""};
}
function parseBackup(text,ids){
 const known=new Set(ids);let data;
 const clean=text.replace(/^\uFEFF/,"");
 if(clean.trimStart().startsWith("#")){
  const records=Object.create(null);let matches=0;
  for(const m of clean.matchAll(/^- \[([ xX])\] ([A-Z]+\d+)\b/gm)){
   matches++;if(known.has(m[2]))records[m[2]]={status:m[1].toLowerCase()==="x"?"verified":"not-started",note:"从旧版 Markdown 自测记录导入。",updatedAt:""};
  }
  if(!matches)throw new Error("没有识别到旧版自测清单；请选择导出的 JSON 或 Markdown 文件。");
  return {records,unknown:matches-Object.keys(records).length};
 }
 try{data=JSON.parse(clean);}catch(error){throw new Error("文件不是有效的 JSON 备份或旧版 Markdown 自测清单。");}
 if(!plain(data))throw new Error("备份内容应为一组练习记录。");
 if("schemaVersion" in data&&data.schemaVersion!==2)throw new Error("无法识别这个备份版本；没有修改已有记录。");
 const source=("records" in data)?data.records:data;
 if(!plain(source))throw new Error("备份中的 records 格式不正确。");
 const records=Object.create(null);let unknown=0;
 for(const [id,value] of Object.entries(source)){
  if(!known.has(id)){unknown++;continue;}
  const record=normalRecord(value);
  if(!record)throw new Error("条目 "+id+" 的学习状态或笔记格式不正确。");
  records[id]=record;
 }
 if(!Object.keys(records).length && !(data.schemaVersion===2 && Object.keys(source).length===0))throw new Error("文件中没有本目录可识别的练习编号；已有记录未修改。");
 return {records,unknown};
}
function mergeRecords(local,incoming,overwrite){
 const output=Object.assign(Object.create(null),local);
 for(const [id,value] of Object.entries(incoming)){if(overwrite||!Object.prototype.hasOwnProperty.call(output,id))output[id]=value;}
 return output;
}
function filtered(tasks,filters,records){
 const q=(filters.query||"").trim().toLowerCase();
 return tasks.filter(t=>(!filters.chapter||t.chapter===filters.chapter)&&(!filters.level||t.level===filters.level)&&(!filters.mode||t.mode===filters.mode)&&(!filters.material||t.material===filters.material)&&(!filters.status||(records[t.id]?.status||"not-started")===filters.status)&&(!q||[t.id,t.title,t.goal,t.sourceScope,...(t.keywords||[])].join(" ").toLowerCase().includes(q)));
}
function counts(tasks,records){
 return ["基础","进阶","扩展"].map(level=>({level,total:tasks.filter(t=>t.level===level).length,verified:tasks.filter(t=>t.level===level&&records[t.id]?.status==="verified").length}));
}
const api={STATUSES,labels,normalRecord,parseBackup,mergeRecords,filtered,counts};
if(typeof module!=="undefined"&&module.exports)module.exports=api;
else scope.PracticeProgress=api;
})(typeof globalThis!=="undefined"?globalThis:this);
