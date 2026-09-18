// B09 非递归后序：访问状态与回退
#include "../../templates/test_support.hpp"

std::vector<int> iterative_postorder(const TreeNode* root) {
    (void)root;
    todo("iterative_postorder");
}

int main() { return practice_test::run([] {
    practice_test::equal(iterative_postorder(nullptr),std::vector<int>{},"empty");
    TreeNode a{1},b{2},c{2},d{4},e{5};
    a.left=&b; a.right=&c; b.right=&d; c.left=&e;
    practice_test::equal(iterative_postorder(&a),std::vector<int>({4,2,5,2,1}),"duplicate values and branches");
    TreeNode single{8};
    practice_test::equal(iterative_postorder(&single),std::vector<int>({8}),"single");
    a.left=nullptr; a.right=&b; b.left=nullptr; b.right=&c; c.left=nullptr;
    practice_test::equal(iterative_postorder(&a),std::vector<int>({2,2,1}),"right chain");
    practice_test::require(a.right==&b && b.right==&c && c.right==nullptr,"links preserved");
}); }
