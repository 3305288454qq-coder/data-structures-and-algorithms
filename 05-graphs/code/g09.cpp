// G09 堆优化 Dijkstra
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<long long> dijkstra_heap(int n, const std::vector<Edge>& edges, int source) {
    (void)n; // 实现后可移除这行占位语句。
    (void)edges; // 实现后可移除这行占位语句。
    (void)source; // 实现后可移除这行占位语句。
    // TODO: 堆优化 Dijkstra，参见 ../problems/g09.md
    todo("dijkstra_heap");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(dijkstra_heap(1,{},0),std::vector<long long>({0}),"singleton");
        practice_test::equal(dijkstra_heap(3,{{0,1,2},{1,2,3},{0,2,10}},0),std::vector<long long>({0,2,5}),"sample");
        practice_test::equal(dijkstra_heap(5,{{0,1,10},{0,2,1},{2,1,1},{1,3,2},{2,3,100}},0),std::vector<long long>({0,2,1,4,INF}),"outdated heap item and unreachable");
        practice_test::equal(dijkstra_heap(3,{{0,1,0},{0,1,5},{1,2,2},{2,1,0}},0),std::vector<long long>({0,0,2}),"zero edge and parallel edges");
        practice_test::equal(dijkstra_heap(3,{{0,1,2},{1,2,3}},1),std::vector<long long>({INF,0,3}),"nonzero source");
        practice_test::equal(dijkstra_heap(3,{{0,1,3000000000LL},{1,2,4000000000LL}},0),std::vector<long long>({0,3000000000LL,7000000000LL}),"long long distances");
    });
}
