// B02 层序遍历
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> level_order(TreeNode* root) {
    std::queue<TreeNode*> pending;
    std::vector<int> result;
    if (root == nullptr)
    {
        return result;
    }
    pending.push(root);

    while (!pending.empty())
    {
        TreeNode* node = pending.front();
        pending.pop();
        result.push_back(node->value);

        if (node->left != nullptr)
        {
            pending.push(node->left);
        }
        if (node->right != nullptr)
        {
            pending.push(node->right);
        }
    }
    
    return result;
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(level_order(nullptr),std::vector<int>{},"empty");
        TreeNode only{9}; practice_test::equal(level_order(&only),std::vector<int>({9}),"singleton");
        TreeNode a{4}, b{5}, left{2,&a,&b}, right{3}, root{1,&left,&right};
        practice_test::equal(level_order(&root),std::vector<int>({1,2,3,4,5}),"level order");
        TreeNode tail{6}, middle{4,nullptr,&tail}, chain{2,&middle,nullptr};
        practice_test::equal(level_order(&chain),std::vector<int>({2,4,6}),"mixed chain");
        TreeNode deep{8}, l{5,nullptr,&deep}, r{7}, incomplete{3,&l,&r};
        practice_test::equal(level_order(&incomplete),std::vector<int>({3,5,7,8}),"incomplete tree");
    });
}
