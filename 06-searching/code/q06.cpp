// Q06 分块查找与块索引 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <memory>
namespace pt = practice_test;


struct BlockIndex { int max_key=0; int begin=0; int end=0; };
int block_search(const std::vector<int>& values, const std::vector<BlockIndex>& index, int key) {
    (void)values; (void)index; (void)key; todo("block_search");
}
int main() { return pt::run([] {
    const std::vector<int> a{7,2,5,16,11,13,24,21,23};
    const std::vector<BlockIndex> idx{{7,0,3},{16,3,6},{24,6,9}};
    pt::equal(block_search(a,idx,13),5,"middle block");
    pt::equal(block_search(a,idx,7),0,"first");
    pt::equal(block_search(a,idx,23),8,"last");
    for(int absent: {0,8,12,25}) pt::equal(block_search(a,idx,absent),-1,"absent key");
    pt::equal(block_search({}, {},4),-1,"empty");
    pt::equal(block_search({3,1,3},{{3,0,3}},3),0,"first duplicate");
}); }
