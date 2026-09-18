// G06 Floyd 全源最短路
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<std::vector<long long>> floyd(std::vector<std::vector<long long>> matrix) {
    (void)matrix; // 实现后可移除这行占位语句。
    // TODO: Floyd 全源最短路，参见 ../problems/g06.md
    todo("floyd");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(floyd({{0}}),std::vector<std::vector<long long>>({{0}}),"singleton");
        practice_test::equal(floyd({{0,2,10},{INF,0,3},{INF,INF,0}}),std::vector<std::vector<long long>>({{0,2,5},{INF,0,3},{INF,INF,0}}),"all pairs sample");
        practice_test::equal(floyd({{0,4,INF,INF},{INF,0,-2,INF},{INF,INF,0,INF},{INF,INF,INF,0}}),std::vector<std::vector<long long>>({{0,4,2,INF},{INF,0,-2,INF},{INF,INF,0,INF},{INF,INF,INF,0}}),"negative edge and INF guard");
        practice_test::equal(floyd({{0,0,9},{INF,0,1},{INF,INF,0}}),std::vector<std::vector<long long>>({{0,0,1},{INF,0,1},{INF,INF,0}}),"zero edge");
        practice_test::equal(floyd({{0,INF,1},{1,0,INF},{INF,1,0}}),std::vector<std::vector<long long>>({{0,2,1},{1,0,2},{2,1,0}}),"k outer loop dependence");
    });
}
