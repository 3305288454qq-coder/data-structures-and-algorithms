// S06 后缀表达式求值
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

long long evaluate_postfix(const std::vector<std::string>& tokens) {
    (void)tokens; // 实现后可移除这行占位语句。
    // TODO: 后缀表达式求值，参见 ../problems/s06.md
    todo("evaluate_postfix");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(evaluate_postfix({"8","3","-","2","*"}), 10LL, "noncommutative sequence");
        practice_test::equal(evaluate_postfix({"-42"}), -42LL, "single negative");
        practice_test::equal(evaluate_postfix({"7","-2","/"}), -3LL, "division truncates toward zero");
        practice_test::equal(evaluate_postfix({"3","8","-"}), -5LL, "subtraction operand order");
        practice_test::equal(evaluate_postfix({"2","3","4","*","+","5","-"}), 9LL, "nested expression");
        practice_test::equal(evaluate_postfix({"2000000000","2","*"}), 4000000000LL, "long long result");
    });
}
