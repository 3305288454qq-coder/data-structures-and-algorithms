// R18 快速选择第 k 小：不必完整排序 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


int quickselect(std::vector<int>& values,std::size_t k) {
    (void)values; (void)k; todo("quickselect");
}
int main() { return pt::run([] {
    for(const auto& original:std::vector<std::vector<int>>{{7,2,2,9,4},{1},{3,3,3,3},{-5,0,9,-2},
            {5,4,3,2,1},{std::numeric_limits<int>::min(),std::numeric_limits<int>::max()}}) {
        auto expected=original; std::sort(expected.begin(),expected.end());
        for(std::size_t k=0;k<original.size();++k) {
            auto values=original;
            pt::equal(quickselect(values,k),expected[k],"kth value");
            std::sort(values.begin(),values.end()); pt::equal(values,expected,"records preserved");
        }
    }
    std::vector<int> empty; bool rejected=false;
    try { (void)quickselect(empty,0); } catch(const std::out_of_range&) { rejected=true; }
    pt::require(rejected,"empty input rejected");
    std::vector<int> one{8}; rejected=false;
    try { (void)quickselect(one,1); } catch(const std::out_of_range&) { rejected=true; }
    pt::require(rejected,"k out of range");
}); }
