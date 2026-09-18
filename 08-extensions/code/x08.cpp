// X08 线段树：点赋值与区间和 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

struct SumTree { int n = 0; std::vector<long long> data; };

SumTree build_sum_tree(const std::vector<int>& values) {
    (void)values;
    todo("build_sum_tree");
}

void point_set(SumTree& tree, int position, long long value) {
    (void)tree;
    (void)position;
    (void)value;
    todo("point_set");
}

long long interval_sum(const SumTree& tree, int left, int right) {
    (void)tree;
    (void)left;
    (void)right;
    todo("interval_sum");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        auto tree=build_sum_tree({1,2,3,4});
        pt::equal(interval_sum(tree,0,4),10LL,"whole");
        pt::equal(interval_sum(tree,1,3),5LL,"middle");
        point_set(tree,2,-3);
        pt::equal(interval_sum(tree,0,4),4LL,"assignment");
        pt::equal(interval_sum(tree,2,2),0LL,"empty range");
        auto empty=build_sum_tree({});
        pt::equal(interval_sum(empty,0,0),0LL,"empty tree");
    });
}
