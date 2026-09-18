// X10 回溯：组合枚举与撤销选择 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"



std::vector<std::vector<int>> combinations(int n, int k) {
    (void)n;
    (void)k;
    todo("combinations");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        auto result=combinations(4,2);
        std::sort(result.begin(),result.end());
        pt::equal(result,std::vector<std::vector<int>>({{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}),"all pairs");
        pt::equal(combinations(0,0),std::vector<std::vector<int>>({{}}),"one empty combination");
        pt::equal(combinations(2,3),std::vector<std::vector<int>>{},"impossible size");
        pt::equal(combinations(3,3),std::vector<std::vector<int>>({{1,2,3}}),"choose all");
    });
}
