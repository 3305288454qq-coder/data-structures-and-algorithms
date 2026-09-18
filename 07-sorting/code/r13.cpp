// R13 自底向上的迭代归并排序 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


void iterative_merge_sort(std::vector<int>& values) {
    (void)values; todo("iterative_merge_sort");
}
int main() { return pt::run([] {
    std::vector<std::vector<int>> cases{{},{7},{5,1,4,2,3},{5,4,3,2,1},{2,2,2},{-2,0,-2,8},
        {std::numeric_limits<int>::max(),0,std::numeric_limits<int>::min()}};
    std::vector<int> many;
    for(int i=0;i<513;++i) many.push_back((i*43)%101-50);
    cases.push_back(many);
    for(auto values:cases) {
        auto expected=values; std::sort(expected.begin(),expected.end());
        iterative_merge_sort(values); pt::equal(values,expected,"iterative merge boundary");
    }
}); }
