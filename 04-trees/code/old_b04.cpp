// B04 由先序中序重建二叉树
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

TreeNode* build_tree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    if (preorder.empty())
    {
        return nullptr;
    }
    
    TreeNode *root = new(TreeNode);
    root->value = preorder[0];

    std::vector<int> leftl_preorder;
    std::vector<int> rightl_preorder;
    std::vector<int> leftl_inorder;
    std::vector<int> rightl_inorder;

    std::size_t i = 0;
    std::size_t j = 1;
    while (inorder[i] != root->value)
    {
        leftl_inorder.push_back(inorder[i]);
        ++i;
    }
    std::size_t left_count = i;
    while (j <= left_count)
    {
        leftl_preorder.push_back(preorder[j]);
        ++j;
    }
    ++i;
    while (i < inorder.size())
    {
        rightl_inorder.push_back(inorder[i]);
        ++i;
    }
    while (j < preorder.size())
    {
        rightl_preorder.push_back(preorder[j]);
        ++j;
    }

    root->left = build_tree(leftl_preorder, leftl_inorder);
    root->right = build_tree(rightl_preorder, rightl_inorder);

    return root;
}

void destroy_tree(TreeNode*& root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 由先序中序重建二叉树，参见 ../problems/b04.md
    todo("destroy_tree");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        TreeNode* root = build_tree({},{}); require(root == nullptr,"empty build"); destroy_tree(root);
        root = build_tree({9},{9}); require(root != nullptr && root->value == 9,"singleton root");
        require(root->left == nullptr && root->right == nullptr,"singleton children"); destroy_tree(root); require(root == nullptr,"destroy nulls");
        root = build_tree({1,2,4,5,3},{4,2,5,1,3});
        require(root != nullptr && root->value == 1,"root");
        practice_test::equal(tree_values(root),std::vector<int>({4,2,5,1,3}),"reconstructed inorder");
        require(root->left != nullptr && root->right != nullptr,"root children");
        require(root->left->value == 2 && root->right->value == 3,"child values");
        require(root->left->left != nullptr && root->left->right != nullptr,"grandchildren");
        require(root->left->left->value == 4 && root->left->right->value == 5,"grandchild values");
        destroy_tree(root); require(root == nullptr,"destroy full"); destroy_tree(root);
        root = build_tree({1,2,3},{1,2,3});
        require(root != nullptr && root->left == nullptr && root->right != nullptr,"right chain root");
        require(root->right->left == nullptr && root->right->right != nullptr && root->right->right->value == 3,"right chain");
        destroy_tree(root); require(root == nullptr,"destroy chain");
    });
}
