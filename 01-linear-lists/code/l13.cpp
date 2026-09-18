// L13 链表环入口与相交结点
// TODO 表示尚未实现；自动测试通过也不直接表示已掌握。
#include "../../templates/test_support.hpp"

ListNode* cycle_entry(ListNode* head) {
    (void)head;
    todo("cycle_entry");
}
ListNode* first_intersection(ListNode* a, ListNode* b) {
    (void)a;
    (void)b;
    todo("first_intersection");
}

int main() { return practice_test::run([] {
    practice_test::require(cycle_entry(nullptr)==nullptr,"empty cycle");
    ListNode self{1,nullptr}; self.next=&self;
    practice_test::require(cycle_entry(&self)==&self,"self cycle");
    ListNode a{1,nullptr},b{2,nullptr},c{3,nullptr},d{4,nullptr};
    a.next=&b; b.next=&c; c.next=&d; d.next=&b;
    practice_test::require(cycle_entry(&a)==&b,"cycle entry not head");
    d.next=nullptr;
    practice_test::require(cycle_entry(&a)==nullptr,"acyclic");
    ListNode x{1,&c},y{1,nullptr};
    practice_test::require(first_intersection(&a,&x)==&c,"shared tail identity");
    practice_test::require(first_intersection(&a,&a)==&a,"same head");
    practice_test::require(first_intersection(&a,&y)==nullptr,"equal values are not shared nodes");
    practice_test::require(first_intersection(nullptr,&a)==nullptr,"empty intersection");
    practice_test::require(a.next==&b && b.next==&c && c.next==&d && d.next==nullptr,"links unchanged");
}); }
