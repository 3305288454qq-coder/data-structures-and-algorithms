// L10 带头结点建表与有序链表合并
// TODO 表示尚未实现；自动测试通过也不直接表示已掌握。
#include "../../templates/test_support.hpp"

ListNode* build_head(const std::vector<int>& values) {
    ListNode* head = new ListNode;

    for (int value : values)
    {
        ListNode* node = new ListNode;
        node->value = value;
        node->next = head->next;
        head->next = node;
    }

    return head;    
}
ListNode* build_tail(const std::vector<int>& values) {
    ListNode* head = new ListNode;
    ListNode* tail = head;

    for (int value : values)
    {
        ListNode* node = new ListNode;
        node->value = value;
        tail->next = node;
        tail = node;
    }

    return head;
}
void merge_sorted(ListNode& a, ListNode& b) {
    ListNode* node_a = a.next;
    ListNode* node_b = b.next;
    ListNode* tail = &a;
    while (node_a != nullptr && node_b != nullptr)
    {
        if (node_a->value > node_b->value)
        {
            tail->next = node_b;
            node_b = node_b->next;
            tail = tail->next;
        }
        else
        {
            tail->next = node_a;
            node_a = node_a->next;
            tail = tail->next;
        }
    }
    if (node_a != nullptr)
    {
        tail->next = node_a;
    }
    else
    {
        tail->next = node_b;
    }

    b.next = nullptr;
}

void destroy_test_list(ListNode* head) { while (head) { auto* next = head->next; delete head; head = next; } }
int main() { return practice_test::run([] {
    auto* head = build_head({1,2,3});
    practice_test::require(head != nullptr, "sentinel exists");
    practice_test::equal(practice_test::list_values(head->next), std::vector<int>({3,2,1}), "head insertion order");
    destroy_test_list(head);
    auto* a = build_tail({1,3,3,8}); auto* b = build_tail({2,3,9});
    practice_test::require(a && b, "two sentinels");
    std::unordered_set<ListNode*> original;
    for (auto* p=a->next; p; p=p->next) original.insert(p);
    for (auto* p=b->next; p; p=p->next) original.insert(p);
    auto* a_equal = a->next->next; auto* b_equal = b->next->next;
    merge_sorted(*a,*b);
    practice_test::equal(practice_test::list_values(a->next), std::vector<int>({1,2,3,3,3,8,9}), "merged values");
    practice_test::require(b->next == nullptr, "second list emptied");
    bool encountered_a = false;
    for (auto* p=a->next; p; p=p->next) {
        practice_test::require(original.erase(p)==1, "reuse each original node once");
        if (p==a_equal) encountered_a=true;
        if (p==b_equal) practice_test::require(encountered_a, "stable equal keys");
    }
    practice_test::require(original.empty(), "no node lost");
    destroy_test_list(a); destroy_test_list(b);
    a=build_tail({}); b=build_tail({});
    practice_test::require(a && b, "empty sentinel");
    merge_sorted(*a,*b);
    practice_test::require(!a->next && !b->next, "empty merge");
    destroy_test_list(a); destroy_test_list(b);
}); }
