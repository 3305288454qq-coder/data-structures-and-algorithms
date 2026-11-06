// S11 中缀转后缀：优先级与括号
#include "../../templates/test_support.hpp"

#include <cctype>
int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
std::vector<std::string> infix_to_postfix(const std::string& expression) {
    std::vector<std::string> output;
    std::size_t i = 0;
    std::stack<char> operators;
    while (i < expression.size())
    {
        char ch = expression[i];
        if (std::isspace(static_cast<unsigned char>(ch)))
        {
            ++i;
            continue;
        }
        if (ch >= '0' && ch <= '9')
        {
            std::string number;
            while (i < expression.size() && expression[i] >= '0' && expression[i] <= '9')
            {
                number += expression[i];
                ++i;
            }
            output.push_back(number);
        }
        if (ch =='+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(ch))
            {
                output.push_back(std::string(1,operators.top()));
                operators.pop();
            }
            
            operators.push(ch);
            ++i;
        }
        else if (ch == '(')
        {
            operators.push(ch);
            ++i;
        }
        else if (ch == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                output.push_back(std::string(1,operators.top()));
                operators.pop();
            }
            if (operators.top() == '(') operators.pop();
            ++i;
        }
    }
    while (!operators.empty()) {
        output.push_back(std::string(1, operators.top()));
        operators.pop();
    }

    return output;
}

int main() { return practice_test::run([] {
    using V = std::vector<std::string>;
    practice_test::equal(infix_to_postfix("12 + 3 * 4"),V({"12","3","4","*","+"}),"precedence");
    practice_test::equal(infix_to_postfix("(12+3)*4"),V({"12","3","+","4","*"}),"parentheses");
    practice_test::equal(infix_to_postfix("20-5-2"),V({"20","5","-","2","-"}),"left associative minus");
    practice_test::equal(infix_to_postfix("24/3*2"),V({"24","3","/","2","*"}),"left associative equal priority");
    practice_test::equal(infix_to_postfix("  ((100)) "),V({"100"}),"nested single value");
    practice_test::equal(infix_to_postfix("0+(8/(2+2))"),V({"0","8","2","2","+","/","+"}),"nested expression");
}); }
