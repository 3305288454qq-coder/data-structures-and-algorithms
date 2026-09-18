// R17 k 路最佳归并树与零长度虚段 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


struct MergePlan { long long cost=0; int dummy_count=0; std::vector<std::vector<long long>> steps; };
MergePlan optimal_merge(const std::vector<long long>& lengths,int k) {
    (void)lengths; (void)k; todo("optimal_merge");
}
void check_plan(const std::vector<long long>& lengths,int k,long long expected_cost) {
    const auto result=optimal_merge(lengths,k);
    pt::equal(result.cost,expected_cost,"optimal cost");
    int expected_dummy=0;
    if(lengths.size()>1) {
        const auto mod=(lengths.size()-1)%static_cast<std::size_t>(k-1);
        expected_dummy=static_cast<int>((static_cast<std::size_t>(k-1)-mod)%static_cast<std::size_t>(k-1));
    }
    pt::equal(result.dummy_count,expected_dummy,"minimum dummy count");
    std::multiset<long long> active(lengths.begin(),lengths.end());
    for(int i=0;i<result.dummy_count;++i) active.insert(0);
    long long computed=0;
    for(const auto& step:result.steps) {
        pt::equal(step.size(),static_cast<std::size_t>(k),"k inputs per step");
        long long sum=0;
        for(long long value:step) {
            const auto it=active.find(value); pt::require(it!=active.end(),"run exists");
            active.erase(it); sum+=value;
        }
        computed+=sum; active.insert(sum);
    }
    pt::equal(computed,result.cost,"step cost agrees");
    pt::equal(active.size(),lengths.empty()?std::size_t{0}:std::size_t{1},"one final run");
    if(!active.empty()) pt::equal(*active.begin(),std::accumulate(lengths.begin(),lengths.end(),0LL),"total length");
}
int main() { return pt::run([] {
    check_plan({2,3,7,10},2,39);
    check_plan({2,3,4,8},3,22);
    check_plan({},3,0); check_plan({9},4,0); check_plan({0,0,0},2,0);
    check_plan({1,1,1,1,1},3,8);
    check_plan({3,4},5,7);
    check_plan({1000000000000LL,1000000000000LL},2,2000000000000LL);
    bool rejected=false;
    try { (void)optimal_merge({1,2},1); } catch(const std::invalid_argument&) { rejected=true; }
    pt::require(rejected,"k must be at least two");
    rejected=false;
    try { (void)optimal_merge({1,-2},2); } catch(const std::invalid_argument&) { rejected=true; }
    pt::require(rejected,"negative length rejected");
    rejected=false;
    try { (void)optimal_merge({1,2},10001); } catch(const std::invalid_argument&) { rejected=true; }
    pt::require(rejected,"simulation k limit prevents enormous dummy allocation");
}); }
