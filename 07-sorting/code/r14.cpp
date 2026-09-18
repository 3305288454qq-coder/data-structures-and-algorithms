// R14 k 路归并：一条段一个候选 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


std::vector<int> merge_runs(const std::vector<std::vector<int>>& runs) {
    (void)runs; todo("merge_runs");
}
int main() { return pt::run([] {
    pt::equal(merge_runs({{1,8},{3,4},{2,9},{5,6}}),std::vector<int>{1,2,3,4,5,6,8,9},"four runs");
    pt::equal(merge_runs({}),std::vector<int>{},"zero runs");
    pt::equal(merge_runs({{},{},{}}),std::vector<int>{},"all empty");
    pt::equal(merge_runs({{1,1,4}}),std::vector<int>{1,1,4},"one run");
    pt::equal(merge_runs({{-3,2},{},{-3,0,7}}),std::vector<int>{-3,-3,0,2,7},"three runs including empty");
    const int hi=std::numeric_limits<int>::max();
    pt::equal(merge_runs({{hi},{hi}}),std::vector<int>{hi,hi},"maximum is real data");
}); }
