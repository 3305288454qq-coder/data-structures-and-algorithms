// R11 小根堆的插入与删除最小值 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


void heap_push(std::vector<int>& heap, int value) {
    (void)heap; (void)value; todo("heap_push");
}
std::optional<int> heap_pop_min(std::vector<int>& heap) {
    (void)heap; todo("heap_pop_min");
}
void check_heap(const std::vector<int>& heap) {
    for(std::size_t i=1;i<heap.size();++i)
        pt::require(heap[(i-1)/2]<=heap[i],"parent no greater than child");
}
int main() { return pt::run([] {
    std::vector<int> h;
    for(int x: {5,1,3,1}) { heap_push(h,x); check_heap(h); }
    pt::equal(h.size(),std::size_t{4},"push grows heap");
    pt::equal(heap_pop_min(h),std::optional<int>{1},"first min"); check_heap(h);
    heap_push(h,-3); check_heap(h);
    for(int expected: {-3,1,3,5}) {
        pt::equal(heap_pop_min(h),std::optional<int>{expected},"mixed operations"); check_heap(h);
    }
    pt::require(h.empty(),"all removed");
    pt::equal(heap_pop_min(h),std::optional<int>{},"empty deletion");
    heap_push(h,std::numeric_limits<int>::max());
    heap_push(h,std::numeric_limits<int>::min());
    pt::equal(heap_pop_min(h),std::optional<int>{std::numeric_limits<int>::min()},"minimum key");
    pt::equal(heap_pop_min(h),std::optional<int>{std::numeric_limits<int>::max()},"maximum key");
    pt::require(h.empty(),"single-element removal");
}); }
