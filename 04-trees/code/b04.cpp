// B04 由先序中序重建二叉树
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

// 两个 vector 始终是原来的完整序列，只读引用不会复制它们。
// 本次子树对应：preorder 从 pre_begin 起的 count 项，
//               inorder  从 in_begin 起的 count 项。
TreeNode* build_range(const std::vector<int>& preorder,
                      const std::vector<int>& inorder,
                      std::size_t pre_begin,
                      std::size_t in_begin,
                      std::size_t count) {
    if (count == 0)
    {
        return nullptr;
    }
    TreeNode *root = new(TreeNode);
    root->value = preorder[pre_begin];
    std::size_t root_pos = in_begin;
    while (inorder[root_pos] != root->value)
    {
        ++root_pos;
    }
    
    std::size_t left_count = root_pos - in_begin;
    root->left = build_range(preorder, inorder, pre_begin + 1, in_begin, left_count);
    root->right = build_range(preorder, inorder, pre_begin + 1 + left_count, root_pos + 1, count - 1 - left_count);
    return root;
}

TreeNode* build_tree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    return build_range(preorder, inorder, 0, 0, preorder.size());
}

void destroy_tree(TreeNode*& root) {
    if (root == nullptr)
    {
        return;
    }
    destroy_tree(root->left);
    destroy_tree(root->right);
    delete(root);
    root = nullptr;
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
