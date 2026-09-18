// G08 关键路径
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> critical_edges(int n, const std::vector<Edge>& activities) {
    (void)n; // 实现后可移除这行占位语句。
    (void)activities; // 实现后可移除这行占位语句。
    // TODO: 关键路径，参见 ../problems/g08.md
    todo("critical_edges");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(critical_edges(4,{{0,1,3},{0,2,2},{1,3,2},{2,3,2}}),std::vector<int>({0,2}),"one critical route");
        practice_test::equal(critical_edges(4,{{0,1,2},{0,2,2},{1,3,2},{2,3,2}}),std::vector<int>({0,1,2,3}),"two critical routes");
        practice_test::equal(critical_edges(3,{{0,1,0},{1,2,3}}),std::vector<int>({0,1}),"zero duration activity");
        practice_test::equal(critical_edges(4,{{1,3,2},{0,2,2},{2,3,2},{0,1,3}}),std::vector<int>({0,3}),"original input edge indices");
        practice_test::equal(critical_edges(2,{{0,1,3000000000LL}}),std::vector<int>({0}),"large duration");
    });
}
