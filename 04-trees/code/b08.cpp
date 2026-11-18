// B08 非递归先序与中序遍历
#include "../../templates/test_support.hpp"

std::vector<int> iterative_preorder(const TreeNode* root) {
    std::vector<int> preorder_values;
    if (root == nullptr)
    {
        return preorder_values;
    }
    std::stack<const TreeNode*> pending;
    pending.push(root);

    while (!pending.empty())
    {
        const TreeNode* node = pending.top();
        pending.pop();
        preorder_values.push_back(node->value);

        if (node->right != nullptr)
        {
            pending.push(node->right);
        }
        if (node->left != nullptr)
        {
            pending.push(node->left);
        }
    }

    return preorder_values;
}
std::vector<int> iterative_inorder(const TreeNode* root) {
    std::vector<int> inorder_values;
    if (root == nullptr)
    {
        return inorder_values;
    }
    std::stack<const TreeNode*> pending;
    const TreeNode* current = root;

    while (current != nullptr || !pending.empty())
    {
        while (current != nullptr)
        {
            pending.push(current);
            current = current->left;
        }

        current = pending.top();
        inorder_values.push_back(current->value);
        pending.pop();
        current = current->right;
    }
    
    return inorder_values;
}

int main() { return practice_test::run([] {
    practice_test::equal(iterative_preorder(nullptr),std::vector<int>{},"empty preorder");
    practice_test::equal(iterative_inorder(nullptr),std::vector<int>{},"empty inorder");
    TreeNode a{1},b{2},c{3},d{4},e{5};
    a.left=&b; a.right=&c; b.right=&d; c.left=&e;
    practice_test::equal(iterative_preorder(&a),std::vector<int>({1,2,4,3,5}),"asymmetric preorder");
    practice_test::equal(iterative_inorder(&a),std::vector<int>({2,4,1,5,3}),"asymmetric inorder");
    practice_test::require(a.left==&b && a.right==&c && b.right==&d && c.left==&e,"tree unchanged");
    TreeNode single{9};
    practice_test::equal(iterative_preorder(&single),std::vector<int>({9}),"single");
    a.left=&b; a.right=nullptr; b.left=&c; b.right=nullptr; c.left=nullptr; c.right=nullptr;
    practice_test::equal(iterative_inorder(&a),std::vector<int>({3,2,1}),"left chain");
    a.left=nullptr; a.right=&b; b.left=nullptr; b.right=&c;
    practice_test::equal(iterative_preorder(&a),std::vector<int>({1,2,3}),"right chain");
}); }
