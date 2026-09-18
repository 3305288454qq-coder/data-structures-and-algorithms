// B03 树高与结点统计
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

int tree_height(TreeNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 树高与结点统计，参见 ../problems/b03.md
    todo("tree_height");
}

int count_nodes(TreeNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 树高与结点统计，参见 ../problems/b03.md
    todo("count_nodes");
}

int count_leaves(TreeNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 树高与结点统计，参见 ../problems/b03.md
    todo("count_leaves");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(tree_height(nullptr),0,"empty height"); practice_test::equal(count_nodes(nullptr),0,"empty count"); practice_test::equal(count_leaves(nullptr),0,"empty leaves");
        TreeNode only{1};
        practice_test::equal(tree_height(&only),1,"single height"); practice_test::equal(count_nodes(&only),1,"single count"); practice_test::equal(count_leaves(&only),1,"single leaf");
        TreeNode tail{4}, middle{3,nullptr,&tail}, left{2,&middle,nullptr}, right{5}, root{1,&left,&right};
        practice_test::equal(tree_height(&root),4,"unbalanced height"); practice_test::equal(count_nodes(&root),5,"node count"); practice_test::equal(count_leaves(&root),2,"leaf count");
        practice_test::equal(tree_height(&left),3,"chain height"); practice_test::equal(count_nodes(&left),3,"chain count"); practice_test::equal(count_leaves(&left),1,"chain leaf");
    });
}
