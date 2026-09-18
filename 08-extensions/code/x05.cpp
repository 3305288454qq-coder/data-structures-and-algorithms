// X05 单调队列：窗口最大值 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



std::vector<int> sliding_maximum(const std::vector<int>& values, int window) {
    (void)values;
    (void)window;
    todo("sliding_maximum");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        pt::equal(sliding_maximum({1,3,-1,-3,5,3,6,7},3), std::vector<int>({3,3,5,5,6,7}), "standard");
        pt::equal(sliding_maximum({2,2,1},2), std::vector<int>({2,2}), "equal maxima");
        pt::equal(sliding_maximum({-2,-5},1), std::vector<int>({-2,-5}), "window one");
        pt::equal(sliding_maximum({1},2), std::vector<int>{}, "too wide");
        pt::equal(sliding_maximum({},1), std::vector<int>{}, "empty");
    });
}
