// G11 遍历整个图与连通分量 — 核心留给学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
namespace pt = practice_test;


std::vector<std::vector<int>> connected_components(const std::vector<std::vector<int>>& graph) {
    (void)graph; todo("connected_components");
}
int main() { return pt::run([] {
    pt::equal(connected_components({{1},{0,2},{1},{4},{3},{}}),
              std::vector<std::vector<int>>{{0,1,2},{3,4},{5}}, "three components");
    pt::equal(connected_components({}), std::vector<std::vector<int>>{}, "empty");
    pt::equal(connected_components({{},{},{}}), std::vector<std::vector<int>>{{0},{1},{2}}, "all isolated");
    pt::equal(connected_components({{0,1,1},{0,0}}), std::vector<std::vector<int>>{{0,1}}, "loops and duplicates");
}); }
