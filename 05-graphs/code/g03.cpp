// G03 Prim 最小生成树
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

long long prim_weight(const std::vector<std::vector<long long>>& matrix) {
    (void)matrix; // 实现后可移除这行占位语句。
    // TODO: Prim 最小生成树，参见 ../problems/g03.md
    todo("prim_weight");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(prim_weight({{0}}),0LL,"single vertex");
        practice_test::equal(prim_weight({{0,1,4},{1,0,2},{4,2,0}}),3LL,"sample weight");
        practice_test::equal(prim_weight({{0,INF},{INF,0}}),-1LL,"disconnected");
        practice_test::equal(prim_weight({{0,0,4},{0,0,2},{4,2,0}}),2LL,"zero weight edge");
        practice_test::equal(prim_weight({{0,1,1},{1,0,1},{1,1,0}}),2LL,"multiple valid MSTs");
        practice_test::equal(prim_weight({{0,3000000000LL,INF},{3000000000LL,0,4000000000LL},{INF,4000000000LL,0}}),7000000000LL,"long long sum");
    });
}
