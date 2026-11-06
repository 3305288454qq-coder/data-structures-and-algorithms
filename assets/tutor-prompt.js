"use strict";
(function () {
 const source=document.getElementById("ai-tutor-prompt");
 const field=document.getElementById("ai-prompt-text");
 const button=document.getElementById("copy-ai-prompt");
 const status=document.getElementById("ai-prompt-status");
 if(!source||!field||!button||!status)return;
 field.value=JSON.parse(source.textContent);
 button.addEventListener("click",async()=>{
  button.disabled=true;
  try{
   if(!navigator.clipboard||typeof navigator.clipboard.writeText!=="function")throw new Error("clipboard unavailable");
   await navigator.clipboard.writeText(field.value);
   status.textContent="完整提示已复制。粘贴到新对话后，填写开头的章节、题号和问题；换设备时另附最近的本章交接。";
  }catch(error){
   field.focus();
   field.select();
   field.setSelectionRange(0,field.value.length);
   status.textContent="浏览器未能自动复制，已选中下方完整提示。电脑按 Ctrl+C，手机使用系统的复制操作。";
  }finally{button.disabled=false;}
 });
})();
