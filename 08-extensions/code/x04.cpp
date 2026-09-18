// X04 单调栈：下一个更大元素 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



std::vector<int> next_greater_indices(const std::vector<int>& values) {
    (void)values;
    todo("next_greater_indices");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        pt::equal(next_greater_indices({2,1,2,4,3}), std::vector<int>({3,2,3,-1,-1}), "mixed");
        pt::equal(next_greater_indices({2,2,2}), std::vector<int>({-1,-1,-1}), "strict duplicates");
        pt::equal(next_greater_indices({3,2,1}), std::vector<int>({-1,-1,-1}), "decreasing");
        pt::equal(next_greater_indices({}), std::vector<int>{}, "empty");
    });
}
