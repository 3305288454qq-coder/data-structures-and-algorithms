"use strict";
const fs=require("fs"),path=require("path");
const root=path.resolve(__dirname,"..");
const chapters=JSON.parse(fs.readFileSync(path.join(root,"curriculum.json"),"utf8"));
const tasks=chapters.flatMap(c=>c.tasks.map(t=>({...t,chapter:c.dir}))),ids=new Set();
for(const task of tasks){
 if(ids.has(task.id))throw new Error("Duplicate ID: "+task.id);ids.add(task.id);
 if(!["基础","进阶","扩展"].includes(task.level)||!["编码","阅读","手推","实验"].includes(task.mode))throw new Error("Invalid classification: "+task.id);
 if(!["已有框架","已有阅读页"].includes(task.material))throw new Error("Invalid material: "+task.id);
 for(const relative of [task.problemPath,task.codePath,task.reference].filter(Boolean)){
  if(/^https?:\/\//.test(relative))continue;
  const full=path.resolve(root,decodeURIComponent(relative.split("#")[0]));
  if(!full.startsWith(root+path.sep)||!fs.existsSync(full))throw new Error("Missing/outside target "+task.id+": "+relative);
 }
 if(task.mode==="编码"&&!task.codePath)throw new Error("Code entry has no source: "+task.id);
}
for(const task of tasks)for(const id of task.prerequisites||[])if(!ids.has(id))throw new Error("Unknown prerequisite "+task.id+" -> "+id);
const visited=new Set(),active=new Set(),byId=new Map(tasks.map(t=>[t.id,t]));
function visit(id){if(active.has(id))throw new Error("Prerequisite cycle: "+id);if(visited.has(id))return;active.add(id);for(const pre of byId.get(id).prerequisites||[])visit(pre);active.delete(id);visited.add(id);}
for(const id of ids)visit(id);
const escapeJson=JSON.stringify(chapters).replace(/</g,"\\u003c");
const template=fs.readFileSync(path.join(root,"tools/index.template.html"),"utf8");
const promptJson=JSON.stringify(fs.readFileSync(path.join(root,"AGENTS.md"),"utf8")).replace(/</g,"\\u003c");
fs.writeFileSync(path.join(root,"index.html"),template.replace("__CURRICULUM__",()=>escapeJson).replace("__TUTOR_PROMPT__",()=>promptJson),"utf8");
console.log(JSON.stringify({chapters:chapters.length,total:tasks.length,code:tasks.filter(t=>t.codePath).length,levels:Object.fromEntries(["基础","进阶","扩展"].map(level=>[level,tasks.filter(t=>t.level===level).length]))}));
