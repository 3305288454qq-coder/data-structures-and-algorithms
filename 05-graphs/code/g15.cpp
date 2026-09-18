// G15 DAG 表达式与公共子表达式 — 核心留给学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
namespace pt = practice_test;


struct ExprNode { char op='v'; long long value=0; int left=-1; int right=-1; };
struct DagValue { long long value=0; std::vector<int> evaluated; };
DagValue evaluate_dag(const std::vector<ExprNode>& nodes, int root) {
    (void)nodes; (void)root; todo("evaluate_dag");
}
int main() { return pt::run([] {
    const auto r=evaluate_dag({{'*',0,3,3},{'v',2,-1,-1},{'v',3,-1,-1},{'+',0,1,2},{'v',99,-1,-1}},0);
    pt::equal(r.value,25LL,"shared expression value");
    pt::equal(r.evaluated,std::vector<int>{1,1,1,1,0},"compute once and skip unreachable");
    const auto sub=evaluate_dag({{'-',0,1,2},{'v',2,-1,-1},{'v',5,-1,-1}},0);
    pt::equal(sub.value,-3LL,"ordered operands");
    pt::equal(sub.evaluated,std::vector<int>{1,1,1},"all necessary nodes");
    const auto leaf=evaluate_dag({{'v',-7,-1,-1}},0);
    pt::equal(leaf.value,-7LL,"constant root");
    pt::equal(leaf.evaluated,std::vector<int>{1},"constant count");
    const auto empty=evaluate_dag({},-1);
    pt::equal(empty.value,0LL,"empty contract"); pt::require(empty.evaluated.empty(),"empty count");
}); }
