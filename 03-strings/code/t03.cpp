// T03 KMP
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> prefix_function(const std::string& pattern) {
    std::vector<int> pi(pattern.size(), 0);

    std::size_t j = 0;

    for (size_t i = 1; i < pattern.size(); ++i)
    {
        while (j != 0 && pattern[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            ++j;
        }
        pi[i] = static_cast<int>(j);
    }

    return pi;
}

std::vector<int> kmp_all(const std::string& text, const std::string& pattern) {
    std::vector<int> pi = prefix_function(pattern);
    std::vector<int> position;
    std::size_t j = 0;

    for (size_t i = 0; i < text.size(); ++i)
    {
        while (j != 0 && text[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j])
        {
            ++j;
        }
        if (j == pattern.size())
        {
            position.push_back(static_cast<int>(i + 1 - pattern.size()));
            j = pi[j - 1];
        }
    }

    return position;
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(prefix_function("a"),std::vector<int>({0}),"single prefix");
        practice_test::equal(prefix_function("ababa"),std::vector<int>({0,0,1,2,3}),"alternating prefix");
        practice_test::equal(prefix_function("aaaa"),std::vector<int>({0,1,2,3}),"repeated prefix");
        practice_test::equal(prefix_function("ababcabab"),std::vector<int>({0,0,1,2,0,1,2,3,4}),"fallback prefix");
        practice_test::equal(kmp_all("abababa","aba"),std::vector<int>({0,2,4}),"overlap");
        practice_test::equal(kmp_all("aaaaa","aaa"),std::vector<int>({0,1,2}),"repeated overlap");
        practice_test::equal(kmp_all("","a"),std::vector<int>{},"empty text");
        practice_test::equal(kmp_all("ab","abc"),std::vector<int>{},"pattern longer");
        practice_test::equal(kmp_all("abcd","z"),std::vector<int>{},"not found");
        practice_test::equal(kmp_all("abcabc","abc"),std::vector<int>({0,3}),"end match");
    });
}
