// L03 合并有序顺序表
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> merge_sorted(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result;  // result 才是容器变量，开始时为空
    std::size_t i = 0;
    std::size_t j = 0;

    for (; i < a.size() && j < b.size(); )
    {
        if (a[i] < b[j])
        {
            result.push_back(a[i]);
            i++;
        }
        else
        {
            result.push_back(b[j]);
            j++;
        }
    }

    for (; i < a.size(); i++)
    {
        result.push_back(a[i]);
    }
    for (; j < b.size(); j++)
    {
        result.push_back(b[j]);
    }

    return result;
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
