// Q02 二分查找第一个匹配
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

int first_equal(const std::vector<int>& values, int target) {
    (void)values; // 实现后可移除这行占位语句。
    (void)target; // 实现后可移除这行占位语句。
    // TODO: 二分查找第一个匹配，参见 ../problems/q02.md
    todo("first_equal");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        const std::vector<std::vector<int>> arrays{{},{7},{1,2,2,4},{-4,0,9},{2,2,2}};
        for (const auto& values : arrays) for (int target : {-5,-4,0,1,2,3,4,7,9,10}) {
            const auto it = std::find(values.begin(),values.end(),target);
            const int expected = it == values.end() ? -1 : static_cast<int>(it-values.begin());
            practice_test::equal(first_equal(values,target),expected,"first matching position");
        }
        std::vector<int> many(10001,5); many.front()=-1; many.back()=9;
        practice_test::equal(first_equal(many,5),1,"long duplicate span");
        practice_test::equal(first_equal(many,9),10000,"last position");
    });
}
