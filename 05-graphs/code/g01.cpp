// G01 邻接表与邻接矩阵
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<std::vector<int>> build_adjacency(int n, const std::vector<std::pair<int, int>>& edges) {
    (void)n; // 实现后可移除这行占位语句。
    (void)edges; // 实现后可移除这行占位语句。
    // TODO: 邻接表与邻接矩阵，参见 ../problems/g01.md
    todo("build_adjacency");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        auto check = [&](int n,const std::vector<std::pair<int,int>>& edges) {
            auto actual = build_adjacency(n,edges);
            practice_test::equal(actual.size(),static_cast<std::size_t>(n),"vertex count");
            std::vector<std::vector<int>> expected(static_cast<std::size_t>(n));
            for (auto edge : edges) expected[edge.first].push_back(edge.second);
            for (int i = 0; i < n; ++i) {
                std::sort(actual[i].begin(),actual[i].end()); std::sort(expected[i].begin(),expected[i].end());
                practice_test::equal(actual[i],expected[i],"directed outgoing edges");
            }
        };
        check(0,{}); check(4,{}); check(3,{{0,1},{0,2},{1,2}});
        check(5,{{1,1},{0,2},{2,0},{0,2},{3,0}});
    });
}
