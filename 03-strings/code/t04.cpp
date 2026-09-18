// T04 KMP：pi 与 1 基 next 约定对照
#include "../../templates/test_support.hpp"

std::vector<int> pi_to_next(const std::vector<int>& pi) {
    (void)pi;
    todo("pi_to_next");
}
int find_with_next(const std::string& text, const std::string& pattern, const std::vector<int>& next) {
    (void)text;
    (void)pattern;
    (void)next;
    todo("find_with_next");
}

int main() { return practice_test::run([] {
    practice_test::equal(pi_to_next({0,0,1,2,3}),std::vector<int>({0,0,1,1,2,3}),"ababa next");
    practice_test::equal(pi_to_next({0,1,2,3}),std::vector<int>({0,0,1,2,3}),"aaaa next");
    practice_test::equal(pi_to_next({}),std::vector<int>({0}),"empty table");
    practice_test::equal(find_with_next("zzababa","ababa",{0,0,1,1,2,3}),2,"suffix match");
    practice_test::equal(find_with_next("abababa","ababa",{0,0,1,1,2,3}),0,"first match");
    practice_test::equal(find_with_next("aaaab","aaaa",{0,0,1,2,3}),0,"repeated prefix");
    practice_test::equal(find_with_next("abc","d",{0,0}),-1,"missing");
    practice_test::equal(find_with_next("ab","ababa",{0,0,1,1,2,3}),-1,"pattern longer");
    practice_test::equal(find_with_next("","",{0}),0,"empty pattern");
}); }
