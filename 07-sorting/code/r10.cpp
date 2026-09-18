// R10 稳定计数排序：负数偏移与值域限制 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


struct Record { int key=0; int serial=0; };
bool operator==(const Record& a,const Record& b) { return a.key==b.key && a.serial==b.serial; }
std::vector<Record> counting_sort(const std::vector<Record>& input, int max_range) {
    (void)input; (void)max_range; todo("counting_sort");
}
int main() { return pt::run([] {
    const std::vector<Record> data{{2,0},{-1,1},{2,2},{0,3},{-1,4}};
    pt::equal(counting_sort(data,100),std::vector<Record>{{-1,1},{-1,4},{0,3},{2,0},{2,2}},"stable signed records");
    pt::equal(counting_sort({},100),std::vector<Record>{},"empty");
    pt::equal(counting_sort({{7,0}},1),std::vector<Record>{{7,0}},"single");
    pt::equal(counting_sort({{2,0},{2,1},{2,2}},1),std::vector<Record>{{2,0},{2,1},{2,2}},"all equal");
    const int hi=std::numeric_limits<int>::max();
    pt::equal(counting_sort({{hi,0},{hi-1,1},{hi,2}},2),
              std::vector<Record>{{hi-1,1},{hi,0},{hi,2}},"small range near int max");
    bool rejected=false;
    try { (void)counting_sort({{std::numeric_limits<int>::min(),0},{hi,1}},1000); }
    catch(const std::length_error&) { rejected=true; }
    pt::require(rejected,"huge range rejected before allocation");
    rejected=false;
    try { (void)counting_sort({{1,0}},0); }
    catch(const std::invalid_argument&) { rejected=true; }
    pt::require(rejected,"nonpositive limit rejected");
    std::vector<Record> many;
    for(int i=0;i<600;++i) many.push_back({(i*37)%23-11,i});
    auto expected=many;
    std::stable_sort(expected.begin(),expected.end(),[](const Record& a,const Record& b){return a.key<b.key;});
    pt::equal(counting_sort(many,23),expected,"many duplicates and stability");
}); }
