// R08 归并排序
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

void sort_values(std::vector<int>& values) {
    (void)values; // 实现后可移除这行占位语句。
    // TODO: 归并排序，参见 ../problems/r08.md
    todo("sort_values");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        std::vector<std::vector<int>> cases{{},{7},{0,0,0},{5,1,3,1,0},{0,1,2,3,4},{9,7,5,3,1},{1,1,1,1,1}};
        cases.push_back({-5,0,-2,8,-5});
        cases.push_back({std::numeric_limits<int>::max(),0,std::numeric_limits<int>::min(),-1,1});
        std::vector<int> generated;
        for (int i = 0; i < 257; ++i) generated.push_back((i*73+17)%101-50);
        cases.push_back(generated);
        std::vector<int> reverse_order;
        for (int i = 512; i >= 0; --i) reverse_order.push_back(i);
        cases.push_back(reverse_order);
        for (std::size_t index = 0; index < cases.size(); ++index) {
            auto actual = cases[index]; auto expected = actual;
            std::sort(expected.begin(),expected.end()); // 这里只生成测试答案，不是待实现算法。
            sort_values(actual);
            practice_test::equal(actual,expected,"sort case " + std::to_string(index) + ": order and multiset");
        }
    });
}
