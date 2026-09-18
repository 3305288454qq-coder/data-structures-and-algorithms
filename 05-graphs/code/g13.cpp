// G13 Dijkstra 的前驱与带权路径 — 核心留给学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
namespace pt = practice_test;


struct WeightedPaths { std::vector<long long> distance; std::vector<int> parent; };
WeightedPaths dijkstra_paths(const std::vector<std::vector<long long>>& matrix, int source) {
    (void)matrix; (void)source; todo("dijkstra_paths");
}
std::vector<int> restore_weighted_path(const WeightedPaths& result, int source, int target) {
    (void)result; (void)source; (void)target; todo("restore_weighted_path");
}
void check_weighted_path(const std::vector<std::vector<long long>>& m,
                         const WeightedPaths& r, int source, int target) {
    const auto path=restore_weighted_path(r,source,target);
    if (r.distance[static_cast<std::size_t>(target)]==INF) {
        pt::require(path.empty(),"unreachable has no path"); return;
    }
    pt::require(!path.empty() && path.size()<=m.size(),"finite acyclic path");
    pt::equal(path.front(),source,"source"); pt::equal(path.back(),target,"target");
    long long sum=0;
    for(std::size_t i=1;i<path.size();++i) {
        pt::require(path[i]>=0 && path[i]<static_cast<int>(m.size()),"vertex in range");
        const auto w=m[static_cast<std::size_t>(path[i-1])][static_cast<std::size_t>(path[i])];
        pt::require(w!=INF,"edge exists"); sum+=w;
    }
    pt::equal(sum,r.distance[static_cast<std::size_t>(target)],"path weight");
}
int main() { return pt::run([] {
    const std::vector<std::vector<long long>> m{{0,0,9,INF},{0,0,4,INF},{INF,INF,0,INF},{INF,INF,INF,0}};
    const auto r=dijkstra_paths(m,0);
    pt::equal(r.distance,std::vector<long long>{0,0,4,INF},"zero edge and unreachable");
    pt::equal(r.parent.size(),m.size(),"parent size");
    pt::equal(r.parent[0],0,"source parent"); pt::equal(r.parent[3],-1,"unreachable parent");
    for(int t=0;t<4;++t) check_weighted_path(m,r,0,t);
    const std::vector<std::vector<long long>> ties{{0,1,1,INF},{INF,0,INF,1},{INF,INF,0,1},{INF,INF,INF,0}};
    const auto both=dijkstra_paths(ties,0);
    pt::equal(both.distance,std::vector<long long>{0,1,1,2},"ties");
    check_weighted_path(ties,both,0,3);
    const auto empty=dijkstra_paths({},-1);
    pt::require(empty.distance.empty() && empty.parent.empty(),"empty");
    pt::equal(restore_weighted_path(empty,-1,-1),std::vector<int>{},"empty path");
}); }
