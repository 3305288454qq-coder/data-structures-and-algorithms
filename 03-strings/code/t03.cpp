// T03 KMP
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> prefix_function(const std::string& pattern) {
    (void)pattern; // 实现后可移除这行占位语句。
    // TODO: KMP，参见 ../problems/t03.md
    todo("prefix_function");
}

std::vector<int> kmp_all(const std::string& text, const std::string& pattern) {
    (void)text; // 实现后可移除这行占位语句。
    (void)pattern; // 实现后可移除这行占位语句。
    // TODO: KMP，参见 ../problems/t03.md
    todo("kmp_all");
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
