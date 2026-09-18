// L05 原地反转单链表
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

ListNode* reverse_list(ListNode* head) {
    (void)head; // 实现后可移除这行占位语句。
    // TODO: 原地反转单链表，参见 ../problems/l05.md
    todo("reverse_list");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        require(reverse_list(nullptr) == nullptr, "empty");
        ListNode only{9};
        require(reverse_list(&only) == &only && only.next == nullptr, "singleton identity");
        ListNode b{2}, a{1,&b};
        ListNode* pair = reverse_list(&a);
        require(pair == &b && b.next == &a && a.next == nullptr, "two nodes preserve identity");
        ListNode z{3}, y{2,&z}, x{1,&y};
        ListNode* reversed = reverse_list(&x);
        require(reversed == &z && z.next == &y && y.next == &x && x.next == nullptr, "three pointer directions");
        practice_test::equal(list_values(reversed), std::vector<int>({3,2,1}), "reversed values");
        require(reverse_list(reversed) == &x, "reverse twice restores head");
        practice_test::equal(list_values(&x), std::vector<int>({1,2,3}), "reverse twice values");
    });
}
