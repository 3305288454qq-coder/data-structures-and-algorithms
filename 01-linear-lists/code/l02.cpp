// L02 原地删除指定值
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

int remove_value(std::vector<int>& values, int value) {
    int kept = 0;

    for (std::size_t i = 0; i < values.size(); i++){
        if (values[i] != value){
            values[kept] = values[i];
            kept++;
        }
    }
    
    return kept;
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        const std::vector<std::vector<int>> inputs{{}, {3,3}, {1,2,4}, {3,2,2,3}, {3,1,3,2,3,3,4}};
        for (auto values : inputs) {
            std::vector<int> expected;
            for (int value : values) if (value != 3) expected.push_back(value);
            const int length = remove_value(values, 3);
            practice_test::equal(length, static_cast<int>(expected.size()), "logical length");
            require(values.size() >= expected.size(), "storage holds logical prefix");
            practice_test::equal(std::vector<int>(values.begin(), values.begin() + length), expected, "stable retained prefix");
        }
    });
}
