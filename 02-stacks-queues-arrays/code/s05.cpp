// S05 括号匹配
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

bool brackets_match(const std::string& text) {
    (void)text; // 实现后可移除这行占位语句。
    // TODO: 括号匹配，参见 ../problems/s05.md
    todo("brackets_match");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        for (const auto& text : std::vector<std::string>{"", "()", "{[()]}", "()[]{}", "((()))"})
            require(brackets_match(text), "matched: " + text);
        for (const auto& text : std::vector<std::string>{"(", ")", "([)]", "][", "(()", "())", "{]"})
            require(!brackets_match(text), "unmatched: " + text);
    });
}
