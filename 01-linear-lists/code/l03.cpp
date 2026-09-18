// L03 合并有序顺序表
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> merge_sorted(const std::vector<int>& a, const std::vector<int>& b) {
    (void)a; // 实现后可移除这行占位语句。
    (void)b; // 实现后可移除这行占位语句。
    // TODO: 合并有序顺序表，参见 ../problems/l03.md
    todo("merge_sorted");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        const std::vector<std::pair<std::vector<int>, std::vector<int>>> cases{
            {{}, {}}, {{}, {1,1}}, {{2}, {}}, {{1,3,5}, {2,3,6}},
            {{1,1}, {1,1,1}}, {{-9,0}, {2,4,6}}, {{1,5,9}, {-4,-1}}
        };
        for (const auto& input : cases) {
            auto expected = input.first;
            expected.insert(expected.end(), input.second.begin(), input.second.end());
            std::sort(expected.begin(), expected.end());
            practice_test::equal(merge_sorted(input.first, input.second), expected, "merge keeps all values");
        }
    });
}
