// S01 顺序栈
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

bool push(ArrayStack& stack, int value) {
    (void)stack; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 顺序栈，参见 ../problems/s01.md
    todo("push");
}

bool pop(ArrayStack& stack, int& value) {
    (void)stack; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 顺序栈，参见 ../problems/s01.md
    todo("pop");
}

bool peek(const ArrayStack& stack, int& value) {
    (void)stack; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 顺序栈，参见 ../problems/s01.md
    todo("peek");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        ArrayStack stack; int value = 0;
        require(!pop(stack, value) && !peek(stack, value), "empty operations");
        for (int i = 0; i < CAPACITY; ++i) require(push(stack, i), "fill stack");
        practice_test::equal(stack.top, CAPACITY, "full top");
        require(!push(stack, -1), "full stack rejects");
        require(peek(stack, value), "peek full"); practice_test::equal(value, CAPACITY-1, "peek value"); practice_test::equal(stack.top, CAPACITY, "peek does not remove");
        for (int i = CAPACITY - 1; i >= 0; --i) { require(pop(stack,value), "pop full"); practice_test::equal(value, i, "LIFO"); }
        require(!pop(stack,value), "empty after drain"); practice_test::equal(stack.top, 0, "empty top");
        require(push(stack, 42) && pop(stack,value), "reuse"); practice_test::equal(value, 42, "reuse value");
    });
}
