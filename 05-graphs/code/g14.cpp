// G14 Floyd 的 next 矩阵与路径恢复 — 核心留给学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
namespace pt = practice_test;


struct FloydPaths {
    std::vector<std::vector<long long>> distance;
    std::vector<std::vector<int>> next;
};
FloydPaths floyd_paths(const std::vector<std::vector<long long>>& matrix) {
    (void)matrix; todo("floyd_paths");
}
std::vector<int> restore_floyd_path(const FloydPaths& result, int from, int to) {
    (void)result; (void)from; (void)to; todo("restore_floyd_path");
}
int main() { return pt::run([] {
    const auto r=floyd_paths({{0,2,8,INF},{INF,0,-1,INF},{INF,INF,0,INF},{INF,INF,INF,0}});
    pt::equal(r.distance,std::vector<std::vector<long long>>{{0,2,1,INF},{INF,0,-1,INF},{INF,INF,0,INF},{INF,INF,INF,0}},"negative edge no negative cycle");
    pt::equal(r.next.size(),std::size_t{4},"next rows");
    for(const auto& row:r.next) pt::equal(row.size(),std::size_t{4},"next columns");
    pt::equal(r.next[0][2],1,"first hop is not final target");
    pt::equal(r.next[2][0],-1,"unreachable next");
    pt::equal(restore_floyd_path(r,0,2),std::vector<int>{0,1,2},"restored path");
    pt::equal(restore_floyd_path(r,2,0),std::vector<int>{},"unreachable");
    pt::equal(restore_floyd_path(r,1,1),std::vector<int>{1},"self");
    const auto single=floyd_paths({{0}});
    pt::equal(single.distance,std::vector<std::vector<long long>>{{0}},"single distance");
    pt::equal(single.next,std::vector<std::vector<int>>{{0}},"single next");
    const auto empty=floyd_paths({});
    pt::require(empty.distance.empty() && empty.next.empty(),"empty matrices");
}); }
