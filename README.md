# 数据结构与算法练习

配合王道考研 2027，保留你已经听完约 2022 年课程的背景。按章练习与验证，不重新安排整门理论课，也不设每日题量。

- [打开分层导航](index.html)：基础 / 进阶 / 扩展，按章节、练习方式、资料与个人状态筛选。
- [开始使用](START_HERE.md) · [自动自测与结果含义](TESTING.md)
- [按顺序的完整目录](PRACTICE_ORDER.md) · [本次改进与覆盖对照](references/IMPLEMENTATION_REPORT.md)
- [外部排序专题](07-sorting/external/README.md) · [学习进度](notes/learning_progress.md)

当前 119 项学习入口，95 项带 C++ 框架。基础 72、进阶 28、扩展 19 分开统计。阅读/手推页有具体任务；不会用空的“代码链接”冒充可运行练习。

## 学习方式

每章可开一个新对话：首页上方展开“复制这段话给新的ai对话或者工作区”，复制完整提示并填写章节。辅导与Notion整理规则统一维护在[AGENTS.md](AGENTS.md)，AI按学习记录中的本章交接接续。


保留原 L01 等49题编号与算法函数内容；新题顺延。TODO 核心留给你实现，自动测试检查已准备的样例和边界。未实现、测试失败、测试通过严格区分。
浏览器旧勾选会迁移成有说明的“已核对”记录。新记录支持状态、卡点与证据，以及 JSON 备份/导入；不会自动修改 Markdown、Notion 或认定掌握。

## 章节入口

- [按需补充的算法基础](00-foundations/README.md)：3 项。
- [线性表](01-linear-lists/README.md)：15 项。
- [栈、队列和数组](02-stacks-queues-arrays/README.md)：14 项。
- [串](03-strings/README.md)：6 项。
- [树与二叉树](04-trees/README.md)：13 项。
- [图](05-graphs/README.md)：17 项。
- [查找](06-searching/README.md)：13 项。
- [排序](07-sorting/README.md)：24 项。
- [兴趣扩展](08-extensions/README.md)：14 项。

## 从哪里继续

当前具体练习以 [学习记录](notes/learning_progress.md) 为准。可以先浏览感兴趣的计数排序、败者树等主题；难点不需要全部排在第一轮。
原学校/PTA作业保留在 D:/Basic Programming Practice，工具练习保留在 D:/Developer Tools Practice。本目录独立同步到公开仓库 [data-structures-and-algorithms](https://github.com/3305288454qq-coder/data-structures-and-algorithms)，编译输出由 `.gitignore` 排除。2026-09-18 的仓库准备与上传由助手按用户本次明确授权代做，不计为算法完成或用户 Git 实操。

## 维护材料

导航元数据来源为 curriculum.json，重新生成导航使用 tools/build_navigation.cjs；Markdown 阅读页使用 tools/render_pages.cjs。学习者的代码文件不由导航生成器覆盖。
