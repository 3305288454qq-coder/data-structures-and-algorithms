// S11 中缀转后缀：优先级与括号
#include "../../templates/test_support.hpp"

#include <cctype>
std::vector<std::string> infix_to_postfix(const std::string& expression) {
    (void)expression;
    todo("infix_to_postfix");
}

int main() { return practice_test::run([] {
    using V=std::vector<std::string>;
    practice_test::equal(infix_to_postfix("12 + 3 * 4"),V({"12","3","4","*","+"}),"precedence");
    practice_test::equal(infix_to_postfix("(12+3)*4"),V({"12","3","+","4","*"}),"parentheses");
    practice_test::equal(infix_to_postfix("20-5-2"),V({"20","5","-","2","-"}),"left associative minus");
    practice_test::equal(infix_to_postfix("24/3*2"),V({"24","3","/","2","*"}),"left associative equal priority");
    practice_test::equal(infix_to_postfix("  ((100)) "),V({"100"}),"nested single value");
    practice_test::equal(infix_to_postfix("0+(8/(2+2))"),V({"0","8","2","2","+","/","+"}),"nested expression");
}); }
