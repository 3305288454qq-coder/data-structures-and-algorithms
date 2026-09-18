// X03 二分答案：最小运输容量 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



long long minimum_capacity(const std::vector<int>& weights, int days) {
    (void)weights;
    (void)days;
    todo("minimum_capacity");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        pt::equal(minimum_capacity({1,2,3,4,5}, 2), 9LL, "two days");
        pt::equal(minimum_capacity({1,2,3,4,5}, 1), 15LL, "one day");
        pt::equal(minimum_capacity({1,2,3,4,5}, 10), 5LL, "many days");
        pt::equal(minimum_capacity({}, 3), 0LL, "empty");
        pt::equal(minimum_capacity({2000000000,2000000000}, 1), 4000000000LL, "wide bounds");
    });
}
