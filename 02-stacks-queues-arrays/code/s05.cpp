// S05 括号匹配
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
// is_pair(辅助函数)
// bool is_pair(char open, char close) {
//     return (open == '(' && close == ')') ||
//            (open == '[' && close == ']') ||
//            (open == '{' && close == '}');
// }
bool brackets_match(const std::string& text) {
    std::vector<char> stack_data(text.size());
    std::size_t top = 0;
    for (char ch : text)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            stack_data[top++] = ch;
        }
        else
        {
            if (top == 0) return false;
            char top_char = stack_data[top - 1];
            // if (!is_pair(top_char, ch)) return false; (如果用is_函数则可以替代以下的switch语句)
            char open_expected;
            switch (ch)
            {
                case ')': open_expected = '('; break;
                case ']': open_expected = '['; break;
                case '}': open_expected = '{'; break;
                default: return false;
            }
            if (top_char != open_expected) return false;
            --top;
        }
    }
    return top == 0;
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
