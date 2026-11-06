// L06 倒数第 k 个结点
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

ListNode* kth_from_end(ListNode* head, int k) {
    if (k <= 0) return nullptr;

    ListNode* ahead = head;
    ListNode* follow = head;
    for (int i = 0; i < k; i++)
    {
        if (ahead != nullptr)
        {
            ahead = ahead->next;
        }
        else return nullptr;
    }

    while (ahead != nullptr)
    {
        ahead = ahead->next;
        follow = follow->next;
    }

    return follow;
    
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        require(kth_from_end(nullptr, 1) == nullptr, "empty");
        ListNode c{30}, b{20,&c}, a{10,&b};
        require(kth_from_end(&a, 1) == &c, "last");
        require(kth_from_end(&a, 2) == &b, "middle");
        require(kth_from_end(&a, 3) == &a, "first");
        require(kth_from_end(&a, 0) == nullptr, "zero k");
        require(kth_from_end(&a, -2) == nullptr, "negative k");
        require(kth_from_end(&a, 4) == nullptr, "too large k");
        practice_test::equal(list_values(&a), std::vector<int>({10,20,30}), "read-only list");
    });
}
