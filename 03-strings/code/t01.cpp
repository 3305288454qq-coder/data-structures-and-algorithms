// T01 串的基本操作
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::string take_substring(const std::string& text, int start, int length) {
    (void)text; // 实现后可移除这行占位语句。
    (void)start; // 实现后可移除这行占位语句。
    (void)length; // 实现后可移除这行占位语句。
    // TODO: 串的基本操作，参见 ../problems/t01.md
    todo("take_substring");
}

int compare_strings(const std::string& a, const std::string& b) {
    (void)a; // 实现后可移除这行占位语句。
    (void)b; // 实现后可移除这行占位语句。
    // TODO: 串的基本操作，参见 ../problems/t01.md
    todo("compare_strings");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(take_substring("abcdef",1,3), std::string("bcd"), "middle substring");
        practice_test::equal(take_substring("",0,0), std::string(), "empty substring");
        practice_test::equal(take_substring("abc",3,0), std::string(), "end zero length");
        practice_test::equal(take_substring("abc",0,3), std::string("abc"), "whole string");
        for (const auto& pair : std::vector<std::pair<std::string,std::string>>{{"",""},{"","a"},{"a",""},{"abc","abc"},{"abc","abcd"},{"abd","abc"}}) {
            const int expected = pair.first < pair.second ? -1 : pair.first > pair.second ? 1 : 0;
            practice_test::equal(compare_strings(pair.first,pair.second),expected,"lexicographic -1/0/1");
        }
    });
}
