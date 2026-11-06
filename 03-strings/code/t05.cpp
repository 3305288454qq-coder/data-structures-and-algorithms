// T05 KMP nextval 优化与等价性验证
#include "../../templates/test_support.hpp"

std::vector<int> build_nextval(const std::string& pattern) {
    std::vector<int> nextval(pattern.size() + 1, 0);
    std::size_t i = 1;
    std::size_t j = 0;
    while (i < pattern.size())
    {
        if (j == 0 || pattern[i - 1] == pattern[j - 1])
        {
            ++i;
            ++j;
            
            if (pattern[i - 1] != pattern[j - 1])
            {
                nextval[i] = static_cast<int>(j);
            }
            else
            {
                nextval[i] = nextval[j];
            }
        }
        else
        {
            j = nextval[j];
        }
    }
    return nextval;
}
int find_with_nextval(const std::string& text, const std::string& pattern) {
    if (pattern.size() == 0)
    {
        return 0;
    }
    const std::vector<int> nextval = build_nextval(pattern);
    std::size_t i = 0;
    std::size_t j = 1;

    while (i < text.size() && j <= pattern.size())
    {
        if (j == 0 || text[i] == pattern[j - 1])
        {
            ++i; ++j;
        }
        else
        {
            j = nextval[j];
        }
        if (j > pattern.size())
        {
            return static_cast<int>(i - pattern.size());
        }
    }
    return -1;
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
