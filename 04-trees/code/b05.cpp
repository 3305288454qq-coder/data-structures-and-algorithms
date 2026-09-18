// B05 中序线索二叉树
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

void inorder_thread(ThreadNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 中序线索二叉树，参见 ../problems/b05.md
    todo("inorder_thread");
}

std::vector<int> traverse_threaded(ThreadNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: 中序线索二叉树，参见 ../problems/b05.md
    todo("traverse_threaded");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        inorder_thread(nullptr); practice_test::equal(traverse_threaded(nullptr),std::vector<int>{},"empty");
        ThreadNode only{9}; inorder_thread(&only);
        require(only.ltag && only.rtag && only.left == nullptr && only.right == nullptr,"singleton threads");
        practice_test::equal(traverse_threaded(&only),std::vector<int>({9}),"singleton traversal");
        ThreadNode left{2}, right{3}, root{1,&left,&right}; inorder_thread(&root);
        require(!root.ltag && !root.rtag && root.left == &left && root.right == &right,"preserve children");
        require(left.ltag && left.left == nullptr && left.rtag && left.right == &root,"left predecessor/successor");
        require(right.ltag && right.left == &root && right.rtag && right.right == nullptr,"right predecessor/successor");
        practice_test::equal(traverse_threaded(&root),std::vector<int>({2,1,3}),"thread traversal");
        ThreadNode end{4}, chain{5,&end,nullptr}; inorder_thread(&chain);
        require(end.rtag && end.right == &chain && chain.rtag && chain.right == nullptr,"left chain threads");
        practice_test::equal(traverse_threaded(&chain),std::vector<int>({4,5}),"left chain");
    });
}
