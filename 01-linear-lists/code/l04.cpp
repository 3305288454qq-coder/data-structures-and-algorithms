// L04 单链表基本操作
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

bool list_insert(ListNode*& head, int position, int value) {
    (void)head; // 实现后可移除这行占位语句。
    (void)position; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 单链表基本操作，参见 ../problems/l04.md
    todo("list_insert");
}

bool list_erase(ListNode*& head, int position, int& removed) {
    (void)head; // 实现后可移除这行占位语句。
    (void)position; // 实现后可移除这行占位语句。
    (void)removed; // 实现后可移除这行占位语句。
    // TODO: 单链表基本操作，参见 ../problems/l04.md
    todo("list_erase");
}

ListNode* list_at(ListNode* head, int position) {
    (void)head; // 实现后可移除这行占位语句。
    (void)position; // 实现后可移除这行占位语句。
    // TODO: 单链表基本操作，参见 ../problems/l04.md
    todo("list_at");
}

void destroy_list(ListNode*& head) {
    (void)head; // 实现后可移除这行占位语句。
    // TODO: 单链表基本操作，参见 ../problems/l04.md
    todo("destroy_list");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        ListNode* head = nullptr; int removed = 0;
        require(list_at(head, 1) == nullptr, "empty lookup");
        require(!list_erase(head, 1, removed), "empty erase");
        require(!list_insert(head, 0, 10), "invalid insertion");
        require(list_insert(head, 1, 10), "insert head");
        require(list_insert(head, 2, 30), "insert tail");
        require(list_insert(head, 2, 20), "insert middle");
        practice_test::equal(list_values(head), std::vector<int>({10,20,30}), "insert links");
        require(list_at(head, 2) == head->next, "lookup returns actual node");
        require(list_at(head, 0) == nullptr && list_at(head, 4) == nullptr, "invalid lookup");
        require(!list_insert(head, 5, 9), "past-end insertion");
        require(!list_erase(head, 4, removed), "past-end erase");
        practice_test::equal(list_values(head), std::vector<int>({10,20,30}), "invalid calls preserve list");
        require(list_erase(head, 1, removed), "erase head"); practice_test::equal(removed, 10, "removed value");
        require(list_erase(head, 2, removed), "erase tail"); practice_test::equal(removed, 30, "tail value");
        require(list_erase(head, 1, removed), "erase only node"); require(head == nullptr, "empty after erase");
        require(list_insert(head, 1, 7), "reuse");
        destroy_list(head); require(head == nullptr, "destroy nulls head");
        destroy_list(head); require(head == nullptr, "destroy empty");
    });
}
