// L08 有序表去重
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

int unique_sorted(std::vector<int>& values) {
    if (values.size() == 0)
    {
        return 0;
    }

    int unique_count = 1;

    for (size_t i = 0; i < values.size() - 1; i++)
    {
        if (values[i + 1] != values[i])
        {
            values[unique_count++] = values[i + 1];
        }
    }
    
    return unique_count;
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        const std::vector<std::vector<int>> cases{{},{4},{1,1,1},{1,2,3},{1,1,2,2,3,3},{-2,-2,0,0,8,8}};
        for (auto values : cases) {
            auto expected = values; expected.erase(std::unique(expected.begin(), expected.end()), expected.end());
            const int length = unique_sorted(values);
            practice_test::equal(length, static_cast<int>(expected.size()), "unique length");
            require(values.size() >= expected.size(), "storage holds prefix");
            practice_test::equal(std::vector<int>(values.begin(), values.begin() + length), expected, "unique prefix");
        }
    });
}
