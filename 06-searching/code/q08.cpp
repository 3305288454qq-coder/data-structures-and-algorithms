// Q08 完整 AVL 插入与回溯维护 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <memory>
namespace pt = practice_test;


AvlNode* insert_avl(AvlNode* root, AvlNode* fresh) {
    (void)root; (void)fresh; todo("insert_avl");
}
void verify_avl(AvlNode* root, const std::set<int>& expected) {
    std::set<const AvlNode*> seen;
    std::vector<int> actual;
    std::function<int(AvlNode*,long long,long long)> visit =
        [&](AvlNode* p,long long low,long long high) -> int {
            if(!p) return 0;
            pt::require(seen.insert(p).second,"no cycles/shared child");
            pt::require(low<p->value && p->value<high,"BST ordering");
            const int left=visit(p->left,low,p->value);
            actual.push_back(p->value);
            const int right=visit(p->right,p->value,high);
            pt::require(left-right>=-1 && left-right<=1,"balance factor");
            pt::equal(p->height,1+std::max(left,right),"stored height");
            return 1+std::max(left,right);
        };
    (void)visit(root,std::numeric_limits<long long>::min(),std::numeric_limits<long long>::max());
    pt::equal(actual,std::vector<int>(expected.begin(),expected.end()),"all and only inserted keys");
}
int build_and_check(const std::vector<int>& keys) {
    std::vector<std::unique_ptr<AvlNode>> owned;
    std::set<int> expected;
    AvlNode* root=nullptr;
    for(int key:keys) {
        owned.push_back(std::make_unique<AvlNode>());
        owned.back()->value=key;
        root=insert_avl(root,owned.back().get());
        expected.insert(key); verify_avl(root,expected);
    }
    pt::require(root!=nullptr,"nonempty root");
    return root->value;
}
int main() { return pt::run([] {
    for(const auto& seq:std::vector<std::vector<int>>{{30,20,10},{10,20,30},{30,10,20},{10,30,20}})
        pt::equal(build_and_check(seq),20,"four rotation cases");
    (void)build_and_check({50,20,70,10,30,60,80,25,27,26,28,30,-1});
    (void)build_and_check({5,5,5});
    std::vector<int> ascending;
    for(int i=0;i<200;++i) ascending.push_back(i);
    (void)build_and_check(ascending);
}); }
