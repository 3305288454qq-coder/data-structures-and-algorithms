// Q03 二叉搜索树基本操作
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

void bst_insert(TreeNode*& root, int value) {
    (void)root; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 二叉搜索树基本操作，参见 ../problems/q03.md
    todo("bst_insert");
}

bool bst_contains(TreeNode* root, int value) {
    (void)root; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 二叉搜索树基本操作，参见 ../problems/q03.md
    todo("bst_contains");
}

bool bst_erase(TreeNode*& root, int value) {
    (void)root; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 二叉搜索树基本操作，参见 ../problems/q03.md
    todo("bst_erase");
}

void destroy_bst(TreeNode*& root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 二叉搜索树基本操作，参见 ../problems/q03.md
    todo("destroy_bst");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        TreeNode* root = nullptr;
        require(!bst_contains(root,8) && !bst_erase(root,8),"empty operations");
        for (int value : {5,3,8,2,4,7,9,6}) bst_insert(root,value);
        bst_insert(root,5); bst_insert(root,3);
        practice_test::equal(tree_values(root),std::vector<int>({2,3,4,5,6,7,8,9}),"ordered unique nodes");
        for (int value : {2,3,4,5,6,7,8,9}) require(bst_contains(root,value),"find inserted");
        require(!bst_contains(root,1) && !bst_contains(root,10),"find missing");
        require(bst_erase(root,2),"delete leaf");
        practice_test::equal(tree_values(root),std::vector<int>({3,4,5,6,7,8,9}),"leaf deletion links");
        require(bst_erase(root,7),"delete one child");
        practice_test::equal(tree_values(root),std::vector<int>({3,4,5,6,8,9}),"one-child links");
        require(bst_erase(root,5),"delete root with two children");
        practice_test::equal(tree_values(root),std::vector<int>({3,4,6,8,9}),"two-child links");
        require(!bst_erase(root,99),"missing deletion");
        destroy_bst(root); require(root == nullptr,"destroy"); destroy_bst(root);
        bst_insert(root,1); require(bst_erase(root,1),"delete singleton"); require(root == nullptr,"last deletion nulls root");
    });
}
