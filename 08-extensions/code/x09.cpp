// X09 动态规划：最少硬币数 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



int minimum_coins(const std::vector<int>& coins, int target) {
    (void)coins;
    (void)target;
    todo("minimum_coins");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        pt::equal(minimum_coins({1,3,4},6),2,"greedy counterexample");
        pt::equal(minimum_coins({2},3),-1,"unreachable");
        pt::equal(minimum_coins({},0),0,"zero target");
        pt::equal(minimum_coins({},4),-1,"no coins");
        pt::equal(minimum_coins({2,2,5},10),2,"duplicates allowed");
    });
}
