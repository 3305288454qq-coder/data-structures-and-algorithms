// T02 朴素模式匹配
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

int naive_find(const std::string& text, const std::string& pattern) {
    std::size_t n = text.size();
    std::size_t m = pattern.size();
    if (m == 0)
    {
        return 0;
    }
    if (m > n)
    {
        return -1;
    }
    for (size_t i = 0; i <= n - m; i++)
    {
        size_t j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            ++j;
        }
        if (j == m)
        {
            return static_cast<int>(i);
        }
        
    }
    return -1;
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        const std::vector<std::pair<std::string,std::string>> cases{{"",""},{"","x"},{"abc",""},{"ababcabc","abc"},{"abc","z"},{"abc","abcd"},{"abc","bc"},{"aaaaab","aaab"},{"abc","abc"}};
        for (const auto& pair : cases) {
            const auto position = pair.first.find(pair.second);
            const int expected = position == std::string::npos ? -1 : static_cast<int>(position);
            practice_test::equal(naive_find(pair.first,pair.second),expected,"first match: "+pair.first+"/"+pair.second);
        }
    });
}
