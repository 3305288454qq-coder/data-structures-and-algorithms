// X01 前缀和与区间求和 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



std::vector<long long> make_prefix(const std::vector<int>& values) {
    (void)values;
    todo("make_prefix");
}

long long range_sum(const std::vector<long long>& prefix, int left, int right) {
    (void)prefix;
    (void)left;
    (void)right;
    todo("range_sum");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        const auto p = make_prefix({2, -1, 4, 3});
        pt::equal(p, std::vector<long long>({0, 2, 1, 5, 8}), "mixed signs prefix");
        pt::equal(range_sum(p, 1, 3), 3LL, "[1,3)");
        pt::equal(range_sum(p, 2, 2), 0LL, "empty range");
        pt::equal(make_prefix({}), std::vector<long long>({0}), "empty input");
        pt::equal(make_prefix({2000000000, 2000000000}).back(), 4000000000LL, "wide sum");
    });
}
