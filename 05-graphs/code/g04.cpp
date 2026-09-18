// G04 Kruskal 最小生成树
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

long long kruskal_weight(int n, std::vector<Edge> edges) {
    (void)n; // 实现后可移除这行占位语句。
    (void)edges; // 实现后可移除这行占位语句。
    // TODO: Kruskal 最小生成树，参见 ../problems/g04.md
    todo("kruskal_weight");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(kruskal_weight(1,{}),0LL,"single vertex");
        practice_test::equal(kruskal_weight(3,{{0,1,1},{1,2,2},{0,2,4}}),3LL,"sample");
        practice_test::equal(kruskal_weight(3,{{0,1,2}}),-1LL,"disconnected");
        practice_test::equal(kruskal_weight(3,{{0,1,1},{1,2,1},{0,2,1}}),2LL,"ties: weight independent of chosen MST");
        practice_test::equal(kruskal_weight(3,{{0,0,0},{0,1,8},{0,1,0},{1,2,2},{0,2,9}}),2LL,"parallel edges and self loop");
        practice_test::equal(kruskal_weight(3,{{0,1,3000000000LL},{1,2,4000000000LL}}),7000000000LL,"long long sum");
    });
}
