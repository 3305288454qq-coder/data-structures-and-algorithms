// X02 滑动窗口：最短达标区间 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



int min_window_length(const std::vector<int>& values, long long target) {
    (void)values;
    (void)target;
    todo("min_window_length");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        pt::equal(min_window_length({2,3,1,2,4,3}, 7), 2, "minimum is 4+3");
        pt::equal(min_window_length({}, 1), 0, "empty");
        pt::equal(min_window_length({0,1,0}, 1), 1, "zeros");
        pt::equal(min_window_length({1,1}, 3), 0, "unreachable");
        pt::equal(min_window_length({9}, 2), 1, "single");
    });
}
