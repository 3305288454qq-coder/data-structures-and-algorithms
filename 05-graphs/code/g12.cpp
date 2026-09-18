// G12 BFS 最短距离与路径恢复 — 核心留给学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
namespace pt = practice_test;


struct BfsPaths { std::vector<int> distance; std::vector<int> parent; };
BfsPaths bfs_paths(const std::vector<std::vector<int>>& graph, int source) {
    (void)graph; (void)source; todo("bfs_paths");
}
std::vector<int> restore_bfs_path(const BfsPaths& result, int source, int target) {
    (void)result; (void)source; (void)target; todo("restore_bfs_path");
}
int main() { return pt::run([] {
    const std::vector<std::vector<int>> g{{1,2},{3},{3},{0},{}};
    const auto r = bfs_paths(g,0);
    pt::equal(r.distance, std::vector<int>{0,1,1,2,-1}, "BFS distances");
    pt::equal(r.parent.size(), g.size(), "parent size");
    pt::equal(r.parent[0], 0, "source parent");
    pt::equal(r.parent[4], -1, "unreachable parent");
    const auto path = restore_bfs_path(r,0,3);
    pt::equal(path.size(), std::size_t{3}, "shortest path length");
    pt::equal(path.front(), 0, "path start"); pt::equal(path.back(), 3, "path end");
    for (std::size_t i=1;i<path.size();++i) {
        pt::require(path[i-1]>=0 && path[i-1]<static_cast<int>(g.size()), "valid vertex");
        const auto& row=g[static_cast<std::size_t>(path[i-1])];
        pt::require(std::find(row.begin(),row.end(),path[i])!=row.end(), "real edge");
    }
    pt::equal(restore_bfs_path(r,0,0), std::vector<int>{0}, "source to source");
    pt::equal(restore_bfs_path(r,0,4), std::vector<int>{}, "unreachable");
    const auto empty=bfs_paths({},-1);
    pt::require(empty.distance.empty() && empty.parent.empty(), "empty graph");
    pt::equal(restore_bfs_path(empty,-1,-1), std::vector<int>{}, "empty path");
}); }
