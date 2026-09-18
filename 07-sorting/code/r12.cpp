// R12 用原序号检验排序稳定性 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


struct TaggedValue { int key=0; int serial=0; };
bool operator==(const TaggedValue& a,const TaggedValue& b) { return a.key==b.key && a.serial==b.serial; }
void stable_insertion_sort(std::vector<TaggedValue>& records) {
    (void)records; todo("stable_insertion_sort");
}
bool is_stable_sort_of(const std::vector<TaggedValue>& before,const std::vector<TaggedValue>& after) {
    (void)before; (void)after; todo("is_stable_sort_of");
}
int main() { return pt::run([] {
    const std::vector<TaggedValue> original{{2,40},{1,90},{2,10},{1,20}};
    const std::vector<TaggedValue> stable{{1,90},{1,20},{2,40},{2,10}};
    auto output=original; stable_insertion_sort(output);
    pt::equal(output,stable,"stable insertion retains original identity order");
    pt::require(is_stable_sort_of(original,stable),"correct sort accepted");
    pt::require(!is_stable_sort_of(original,{{1,20},{1,90},{2,40},{2,10}}),"unstable rejected");
    pt::require(!is_stable_sort_of(original,original),"unsorted rejected");
    pt::require(!is_stable_sort_of(original,{{1,90},{2,40},{2,10}}),"missing record rejected");
    pt::require(!is_stable_sort_of(original,{{1,90},{1,20},{2,40},{2,40}}),"duplicate substitution rejected");
    std::vector<TaggedValue> empty; stable_insertion_sort(empty);
    pt::require(is_stable_sort_of({},empty),"empty stable");
    std::vector<TaggedValue> same{{3,8},{3,2},{3,9}}; const auto before=same;
    stable_insertion_sort(same); pt::equal(same,before,"all equal keys");
}); }
