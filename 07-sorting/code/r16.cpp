// R16 败者树的构建与胜者替换调整 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <optional>
#include <numeric>
namespace pt = practice_test;


struct LoserTree {
    std::vector<std::optional<int>> keys;
    std::vector<int> losers;
    int leaf_base=1;
    int winner=-1;
};
LoserTree build_loser_tree(const std::vector<std::optional<int>>& keys) {
    (void)keys; todo("build_loser_tree");
}
void replace_winner(LoserTree& tree,std::optional<int> next) {
    (void)tree; (void)next; todo("replace_winner");
}
void test_merge(const std::vector<std::vector<int>>& runs) {
    std::vector<std::optional<int>> keys;
    std::vector<std::size_t> positions(runs.size(),0);
    std::vector<int> expected;
    for(const auto& run:runs) {
        keys.push_back(run.empty()?std::optional<int>{}:std::optional<int>{run.front()});
        expected.insert(expected.end(),run.begin(),run.end());
    }
    std::sort(expected.begin(),expected.end());
    auto tree=build_loser_tree(keys); std::vector<int> actual;
    while(tree.winner!=-1) {
        const int w=tree.winner;
        pt::require(w>=0 && w<static_cast<int>(runs.size()),"winner index valid");
        const auto wi=static_cast<std::size_t>(w);
        pt::require(positions[wi]<runs[wi].size(),"winner not exhausted");
        pt::require(actual.size()<expected.size(),"merge must terminate");
        actual.push_back(runs[wi][positions[wi]++]);
        replace_winner(tree,positions[wi]<runs[wi].size()
            ?std::optional<int>{runs[wi][positions[wi]]}:std::optional<int>{});
    }
    pt::equal(actual,expected,"loser-tree merge");
}
int main() { return pt::run([] {
    auto t=build_loser_tree({1,3,2,5});
    pt::equal(t.leaf_base,4,"four leaves");
    pt::equal(t.losers.size(),std::size_t{4},"internal array");
    pt::equal(t.winner,0,"initial winner");
    pt::equal(t.losers[1],2,"root loser");
    pt::equal(t.losers[2],1,"left loser"); pt::equal(t.losers[3],3,"right loser");
    replace_winner(t,8); pt::equal(t.winner,2,"winner after replacement");
    pt::equal(t.losers[1],1,"updated root loser"); pt::equal(t.losers[2],0,"updated left loser");
    auto ties=build_loser_tree({2,2,2});
    pt::equal(ties.leaf_base,4,"pad non-power-of-two");
    pt::equal(ties.winner,0,"tie by run index");
    replace_winner(ties,std::nullopt); pt::equal(ties.winner,1,"next tied run");
    auto single=build_loser_tree({7});
    pt::equal(single.leaf_base,1,"one leaf has no internal match");
    pt::equal(single.winner,0,"single winner");
    replace_winner(single,9); pt::equal(single.winner,0,"single replacement");
    pt::equal(single.keys[0],std::optional<int>{9},"candidate updated");
    replace_winner(single,std::nullopt); pt::equal(single.winner,-1,"single exhausted");
    bool exhausted_rejected=false;
    try { replace_winner(single,1); } catch(const std::out_of_range&) { exhausted_rejected=true; }
    pt::require(exhausted_rejected,"exhausted nonempty tree rejects replacement");
    test_merge({{1,8},{3,4},{2,9},{5,6}});
    test_merge({{7,8,9}});
    test_merge({{},{-1,2},{-1,3,3}}); test_merge({}); test_merge({{},{}});
    test_merge({{std::numeric_limits<int>::max()},{std::numeric_limits<int>::max()}});
    auto empty=build_loser_tree({});
    pt::equal(empty.winner,-1,"empty winner");
    bool rejected=false;
    try { replace_winner(empty,1); } catch(const std::out_of_range&) { rejected=true; }
    pt::require(rejected,"cannot replace absent winner");
}); }
