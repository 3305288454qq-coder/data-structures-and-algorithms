// S02 链栈
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

void push_linked(ListNode*& top, int value) {
    ListNode* new_node = new ListNode;
    new_node->value = value;
    new_node->next = top;
    top = new_node;
}

bool pop_linked(ListNode*& top, int& value) {
    if (top == nullptr) return false;
    ListNode* old_top = top;
    value = old_top->value;
    top = top->next;
    delete old_top;    
    return true;
}

void clear_stack(ListNode*& top) {
    while (top != nullptr)
    {
        ListNode* clear_top = top;
        top = top->next;
        delete clear_top;
    }
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        ListNode* top = nullptr; int value = 0;
        require(!pop_linked(top,value), "empty");
        push_linked(top,1); push_linked(top,2);
        practice_test::equal(list_values(top), std::vector<int>({2,1}), "stack links");
        require(pop_linked(top,value), "pop two"); practice_test::equal(value, 2, "LIFO");
        require(pop_linked(top,value), "pop one"); practice_test::equal(value, 1, "bottom");
        require(top == nullptr, "last pop nulls top"); require(!pop_linked(top,value), "empty again");
        push_linked(top,3); push_linked(top,4); clear_stack(top); require(top == nullptr, "clear");
        clear_stack(top); require(top == nullptr, "repeat clear");
    });
}
