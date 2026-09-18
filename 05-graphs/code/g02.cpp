// G02 图的 DFS 与 BFS
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> dfs_order(const std::vector<std::vector<int>>& graph, int start) {
    (void)graph; // 实现后可移除这行占位语句。
    (void)start; // 实现后可移除这行占位语句。
    // TODO: 图的 DFS 与 BFS，参见 ../problems/g02.md
    todo("dfs_order");
}

std::vector<int> bfs_order(const std::vector<std::vector<int>>& graph, int start) {
    (void)graph; // 实现后可移除这行占位语句。
    (void)start; // 实现后可移除这行占位语句。
    // TODO: 图的 DFS 与 BFS，参见 ../problems/g02.md
    todo("bfs_order");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        const std::vector<std::vector<int>> graph{{1,2},{3},{3},{}};
        practice_test::equal(dfs_order(graph,0),std::vector<int>({0,1,3,2}),"DFS neighbor order");
        practice_test::equal(bfs_order(graph,0),std::vector<int>({0,1,2,3}),"BFS neighbor order");
        const std::vector<std::vector<int>> cyclic{{0,1,1},{0,2},{1},{}};
        practice_test::equal(dfs_order(cyclic,0),std::vector<int>({0,1,2}),"DFS skips repeats and loop");
        practice_test::equal(bfs_order(cyclic,0),std::vector<int>({0,1,2}),"BFS skips repeats and loop");
        practice_test::equal(dfs_order(cyclic,3),std::vector<int>({3}),"isolated start");
        practice_test::equal(bfs_order(cyclic,3),std::vector<int>({3}),"isolated BFS");
        practice_test::equal(dfs_order({{}},0),std::vector<int>({0}),"singleton");
        practice_test::equal(bfs_order({{}},0),std::vector<int>({0}),"singleton BFS");
    });
}
