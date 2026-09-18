// G05 朴素 Dijkstra
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<long long> dijkstra_matrix(const std::vector<std::vector<long long>>& matrix, int source) {
    (void)matrix; // 实现后可移除这行占位语句。
    (void)source; // 实现后可移除这行占位语句。
    // TODO: 朴素 Dijkstra，参见 ../problems/g05.md
    todo("dijkstra_matrix");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(dijkstra_matrix({{0}},0),std::vector<long long>({0}),"single vertex");
        practice_test::equal(dijkstra_matrix({{0,2,10},{INF,0,3},{INF,INF,0}},0),std::vector<long long>({0,2,5}),"indirect improvement");
        practice_test::equal(dijkstra_matrix({{0,0,8,INF},{INF,0,2,INF},{INF,INF,0,INF},{INF,INF,INF,0}},0),std::vector<long long>({0,0,2,INF}),"zero edge and unreachable");
        practice_test::equal(dijkstra_matrix({{0,2,10},{INF,0,3},{INF,INF,0}},1),std::vector<long long>({INF,0,3}),"nonzero source");
        practice_test::equal(dijkstra_matrix({{0,3000000000LL,INF},{INF,0,4000000000LL},{INF,INF,0}},0),std::vector<long long>({0,3000000000LL,7000000000LL}),"long long distance");
    });
}
