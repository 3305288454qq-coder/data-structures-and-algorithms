// X07 树状数组：单点更新与前缀查询 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



void bit_add(std::vector<long long>& tree, int index, long long delta) {
    (void)tree;
    (void)index;
    (void)delta;
    todo("bit_add");
}

long long bit_prefix(const std::vector<long long>& tree, int count) {
    (void)tree;
    (void)count;
    todo("bit_prefix");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        std::vector<long long> tree(6,0);
        pt::equal(bit_prefix(tree,0),0LL,"zero prefix");
        bit_add(tree,0,3); bit_add(tree,4,7); bit_add(tree,2,-2);
        pt::equal(bit_prefix(tree,5),8LL,"all values");
        pt::equal(bit_prefix(tree,3),1LL,"partial");
        bit_add(tree,0,5);
        pt::equal(bit_prefix(tree,1),8LL,"repeated update");
        pt::equal(bit_prefix(std::vector<long long>(1,0),0),0LL,"empty array");
    });
}
