// G07 拓扑排序
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> topological_order(const std::vector<std::vector<int>>& graph) {
    (void)graph; // 实现后可移除这行占位语句。
    // TODO: 拓扑排序，参见 ../problems/g07.md
    todo("topological_order");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        for (const auto& graph : std::vector<std::vector<std::vector<int>>>{{{}},{{1},{2},{}},{{2},{2},{},{}},{{1,2},{3},{3},{}}})
            topological(graph,topological_order(graph));
        practice_test::equal(topological_order({{1},{0}}),std::vector<int>{},"two-vertex cycle");
        practice_test::equal(topological_order({{0}}),std::vector<int>{},"self loop");
        practice_test::equal(topological_order({{}, {2}, {1}}),std::vector<int>{},"cycle in disconnected component");
    });
}
