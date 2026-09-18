// R15 置换—选择的固定工作区模拟 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


struct ReplacementRuns { std::vector<std::vector<int>> runs; std::size_t peak_resident=0; };
ReplacementRuns replacement_selection(const std::vector<int>& input, std::size_t capacity) {
    (void)input; (void)capacity; todo("replacement_selection");
}
void verify_runs(const std::vector<int>& input,std::size_t capacity,const ReplacementRuns& result) {
    std::vector<int> collected;
    for(const auto& run:result.runs) {
        pt::require(!run.empty(),"no empty output run");
        pt::require(std::is_sorted(run.begin(),run.end()),"each run sorted");
        collected.insert(collected.end(),run.begin(),run.end());
    }
    auto expected=input; std::sort(expected.begin(),expected.end()); std::sort(collected.begin(),collected.end());
    pt::equal(collected,expected,"record multiset preserved");
    pt::require(result.peak_resident<=capacity,"workspace bound");
    pt::equal(result.peak_resident,std::min(input.size(),capacity),"peak includes initial fill");
}
int main() { return pt::run([] {
    const std::vector<int> a{4,1,7,2,6,3,5,0};
    const auto first=replacement_selection(a,3);
    pt::equal(first.runs,std::vector<std::vector<int>>{{1,2,4,6,7},{0,3,5}},"frozen records start next run");
    verify_runs(a,3,first);
    const auto descending=replacement_selection({5,4,3,2,1},2);
    pt::equal(descending.runs,std::vector<std::vector<int>>{{4,5},{2,3},{1}},"descending runs");
    verify_runs({5,4,3,2,1},2,descending);
    for(const auto& input:std::vector<std::vector<int>>{{},{7},{1,2,3,4,5},{4,4,4,4},{3,2,1},
            {std::numeric_limits<int>::min(),std::numeric_limits<int>::max(),0}}) {
        for(std::size_t cap: {std::size_t{1},std::size_t{3},std::size_t{10}})
            verify_runs(input,cap,replacement_selection(input,cap));
    }
    pt::equal(replacement_selection({4,4,4,4},1).runs,std::vector<std::vector<int>>{{4,4,4,4}},"equal values remain in current run");
    pt::equal(replacement_selection({1,2,3,4},1).runs,std::vector<std::vector<int>>{{1,2,3,4}},"ascending capacity one is one run");
    bool rejected=false;
    try { (void)replacement_selection({1},0); } catch(const std::invalid_argument&) { rejected=true; }
    pt::require(rejected,"zero capacity rejected");
}); }
