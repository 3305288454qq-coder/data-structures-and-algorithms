// L12 主元素：候选抵消与最终核验
// TODO 表示尚未实现；自动测试通过也不直接表示已掌握。
#include "../../templates/test_support.hpp"

std::pair<bool,int> majority_element(const std::vector<int>& values) {
    (void)values;
    todo("majority_element");
}

int main() { return practice_test::run([] {
    practice_test::equal(majority_element({}),std::make_pair(false,0),"empty");
    practice_test::equal(majority_element({7}),std::make_pair(true,7),"single");
    practice_test::equal(majority_element({1,2,1,2}),std::make_pair(false,0),"exactly half");
    practice_test::equal(majority_element({1,2,3}),std::make_pair(false,0),"candidate not majority");
    practice_test::equal(majority_element({-2,9,-2,-2}),std::make_pair(true,-2),"negative majority");
    const int hi=std::numeric_limits<int>::max();
    practice_test::equal(majority_element({hi,hi,0}),std::make_pair(true,hi),"extreme value");
}); }
