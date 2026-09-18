// L11 有序表交集、区间删除与循环移位
// TODO 表示尚未实现；自动测试通过也不直接表示已掌握。
#include "../../templates/test_support.hpp"

std::vector<int> intersection_sorted(const std::vector<int>& a, const std::vector<int>& b) {
    (void)a;
    (void)b;
    todo("intersection_sorted");
}
void erase_interval(std::vector<int>& values, int low, int high) {
    (void)values;
    (void)low;
    (void)high;
    todo("erase_interval");
}
void rotate_left(std::vector<int>& values, std::size_t k) {
    (void)values;
    (void)k;
    todo("rotate_left");
}

int main() { return practice_test::run([] {
    practice_test::equal(intersection_sorted({1,1,3,5},{1,1,2,5,5}), std::vector<int>({1,5}), "set intersection");
    practice_test::equal(intersection_sorted({}, {1}), std::vector<int>{}, "empty intersection");
    practice_test::equal(intersection_sorted({1},{2}), std::vector<int>{}, "disjoint");
    std::vector<int> a{5,1,3,2,8,3}; erase_interval(a,2,5);
    practice_test::equal(a,std::vector<int>({1,8}),"stable removal");
    erase_interval(a,8,1); practice_test::equal(a,std::vector<int>({1,8}),"invalid interval");
    erase_interval(a,1,8); practice_test::require(a.empty(),"remove all");
    a={1,2,3,4,5}; rotate_left(a,7);
    practice_test::equal(a,std::vector<int>({3,4,5,1,2}),"modulo rotation");
    rotate_left(a,0); practice_test::equal(a,std::vector<int>({3,4,5,1,2}),"zero rotation");
    a.clear(); rotate_left(a,20); practice_test::require(a.empty(),"empty rotation");
}); }
