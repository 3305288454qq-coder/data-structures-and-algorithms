// T05 KMP nextval 优化与等价性验证
#include "../../templates/test_support.hpp"

std::vector<int> build_nextval(const std::string& pattern) {
    (void)pattern;
    todo("build_nextval");
}
int find_with_nextval(const std::string& text, const std::string& pattern) {
    (void)text;
    (void)pattern;
    todo("find_with_nextval");
}

int main() { return practice_test::run([] {
    practice_test::equal(build_nextval("aaaa"),std::vector<int>({0,0,0,0,0}),"same-character skip");
    practice_test::equal(build_nextval("ababa"),std::vector<int>({0,0,1,0,1,0}),"periodic skip");
    practice_test::equal(build_nextval("abc"),std::vector<int>({0,0,1,1}),"distinct chars");
    practice_test::equal(build_nextval(""),std::vector<int>({0}),"empty nextval");
    const std::vector<std::string> texts{"","a","aaaaab","ababababac","zzabc","xyz","aabaaabaaac"};
    const std::vector<std::string> patterns{"","a","b","aaaab","ababac","abc","aabaaac","longerpattern"};
    for(const auto& text:texts) for(const auto& pattern:patterns) {
        const auto pos=text.find(pattern);
        const int expected=pos==std::string::npos?-1:static_cast<int>(pos);
        practice_test::equal(find_with_nextval(text,pattern),expected,"compare reference: "+text+" / "+pattern);
    }
}); }
