// L04 单链表基本操作
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

bool list_insert(ListNode*& head, int position, int value) {
    if (position < 1) return false;

    if (position == 1) {
        ListNode* node = new ListNode{value, nullptr};
        node->next = head;
        head = node;
        return true;
    }
    else {
        ListNode* p = head;

        for (int current_position = 1; p != nullptr && current_position < position - 1; ++current_position)
        {
            p = p->next;
        }

        if (p == nullptr) {
            return false;
        }

        ListNode* node = new ListNode{value, nullptr};
        node->next = p->next;
        p->next = node;

        return true;
    }
}

bool list_erase(ListNode*& head, int position, int& removed) {
    if (head == nullptr) return false;
    if (position < 1) return false;
    ListNode* p = head;

    if (position == 1)
    {
        removed = p->value;
        head = p->next;
        delete p;
        return true;
    }

    for (int current_position = 1; p != nullptr && current_position < position - 1; ++current_position)
    {
        p = p->next;
    }

    if (p == nullptr || p->next == nullptr) return false;

    ListNode* q = p->next;
    removed = q->value;
    p->next = q->next;
    delete q;

    return true;
}

ListNode* list_at(ListNode* head, int position) {
    if (position < 1) return nullptr;

    ListNode* p = head;

    //按次数循环 
    // for (int i = 0; i < position - 1 && p != nullptr; i++){
    //     p = p->next;
    // }

    for (int current_position = 1; p != nullptr && current_position < position; ++current_position)
    {
        p = p->next;
    }
    
    return p;
}

void destroy_list(ListNode*& head) {
    ListNode* p;
    while (head !=nullptr)
    {
        p = head;
        head = head->next;
        delete p;
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
