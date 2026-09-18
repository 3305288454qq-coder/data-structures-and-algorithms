// B01 二叉树三种遍历
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<int> preorder(TreeNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 二叉树三种遍历，参见 ../problems/b01.md
    todo("preorder");
}

std::vector<int> inorder(TreeNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 二叉树三种遍历，参见 ../problems/b01.md
    todo("inorder");
}

std::vector<int> postorder(TreeNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 二叉树三种遍历，参见 ../problems/b01.md
    todo("postorder");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(preorder(nullptr),std::vector<int>{},"empty preorder");
        practice_test::equal(inorder(nullptr),std::vector<int>{},"empty inorder");
        practice_test::equal(postorder(nullptr),std::vector<int>{},"empty postorder");
        TreeNode leaf{7};
        practice_test::equal(preorder(&leaf),std::vector<int>({7}),"single preorder");
        practice_test::equal(inorder(&leaf),std::vector<int>({7}),"single inorder");
        practice_test::equal(postorder(&leaf),std::vector<int>({7}),"single postorder");
        TreeNode a{4}, b{5}, left{2,&a,&b}, right{3}, root{1,&left,&right};
        practice_test::equal(preorder(&root),std::vector<int>({1,2,4,5,3}),"preorder");
        practice_test::equal(inorder(&root),std::vector<int>({4,2,5,1,3}),"inorder");
        practice_test::equal(postorder(&root),std::vector<int>({4,5,2,3,1}),"postorder");
        TreeNode tail{9}, middle{8,nullptr,&tail}, chain{6,nullptr,&middle};
        practice_test::equal(preorder(&chain),std::vector<int>({6,8,9}),"right chain");
        practice_test::equal(postorder(&chain),std::vector<int>({9,8,6}),"right chain postorder");
    });
}
