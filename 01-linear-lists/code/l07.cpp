// L07 双向循环链表
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

void append_node(DoubleNode& sentinel, int value) {
    (void)sentinel; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 双向循环链表，参见 ../problems/l07.md
    todo("append_node");
}

bool erase_first(DoubleNode& sentinel, int value) {
    (void)sentinel; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 双向循环链表，参见 ../problems/l07.md
    todo("erase_first");
}

void clear_nodes(DoubleNode& sentinel) {
    (void)sentinel; // 实现后可移除这行占位语句。
    // TODO: 双向循环链表，参见 ../problems/l07.md
    todo("clear_nodes");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        DoubleNode sentinel; sentinel.prev = sentinel.next = &sentinel;
        auto check = [&](const std::vector<int>& expected) {
            DoubleNode* p = sentinel.next; DoubleNode* previous = &sentinel;
            for (int value : expected) {
                require(p != nullptr && p != &sentinel, "forward length");
                practice_test::equal(p->value, value, "forward value"); require(p->prev == previous, "back link");
                previous = p; p = p->next;
            }
            require(p == &sentinel && sentinel.prev == previous, "tail returns to sentinel");
            p = sentinel.prev; DoubleNode* next = &sentinel;
            for (auto it = expected.rbegin(); it != expected.rend(); ++it) {
                require(p != nullptr && p != &sentinel, "backward length");
                practice_test::equal(p->value, *it, "backward value"); require(p->next == next, "forward link");
                next = p; p = p->prev;
            }
            require(p == &sentinel && sentinel.next == next, "head returns to sentinel");
        };
        require(!erase_first(sentinel, 1), "erase empty"); check({});
        append_node(sentinel, 10); check({10});
        require(erase_first(sentinel, 10), "erase singleton"); check({});
        append_node(sentinel, 10); append_node(sentinel, 20); append_node(sentinel, 10); check({10,20,10});
        require(erase_first(sentinel, 10), "erase first duplicate"); check({20,10});
        require(erase_first(sentinel, 10), "erase tail"); check({20});
        require(!erase_first(sentinel, 99), "missing value"); check({20});
        clear_nodes(sentinel); check({}); clear_nodes(sentinel); check({});
    });
}
