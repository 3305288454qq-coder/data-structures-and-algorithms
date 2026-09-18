// Q01 顺序查找
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

int linear_search(const std::vector<int>& values, int target) {
    (void)values; // 实现后可移除这行占位语句。
    (void)target; // 实现后可移除这行占位语句。
    // TODO: 顺序查找，参见 ../problems/q01.md
    todo("linear_search");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        const std::vector<std::vector<int>> arrays{{},{7},{8,3,8},{-4,0,9},{2,2,2}};
        for (const auto& values : arrays) for (int target : {-4,0,2,3,7,8,9,10}) {
            const auto it = std::find(values.begin(),values.end(),target);
            const int expected = it == values.end() ? -1 : static_cast<int>(it-values.begin());
            practice_test::equal(linear_search(values,target),expected,"first occurrence");
        }
    });
}
