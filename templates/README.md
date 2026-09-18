# 代码模板怎么用

[首页](../README.md) · [参考资料](../references/README.md) · [自测说明](../TESTING.md)

- [common.hpp](common.hpp)：结构体、容量、INF和辅助函数。
- [test_support.hpp](test_support.hpp)：自动核对、异常与结果分类；不实现目标算法。
- [cpp_starter.cpp](cpp_starter.cpp)：独立新题的空白程序。
- 各章节code目录中的**95个专用框架**：函数接口、TODO和带自动核对的main，优先使用，不用重新搭输入框架。

每个.cpp单独编译运行。通常只填写目标函数，保留main中的测试；不能只删TODO或打印PASS冒充实现。TODO返回2，失败返回1，通过当前测试返回0，详见自测说明。

框架主要采用std::vector/std::string传递输入，便于集中练核心算法；顺序表、栈、链表等目标结构仍按题目要求自己实现。不理解容器长度、引用或结点释放责任时，先看[F02框架前置](../00-foundations/topics/f02.md)。

现成参考实现请查看题目里的对应资料或[OI Wiki](https://oi-wiki.org/)。本地模板刻意留空，先尝试再查卡点；查看完整实现不意味着已掌握。在线提交时再按平台的类、函数签名和输入输出做适配。
