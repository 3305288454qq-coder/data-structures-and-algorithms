// Q05 AVL 单旋与双旋
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

AvlNode* rotate_left(AvlNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: AVL 单旋与双旋，参见 ../problems/q05.md
    todo("rotate_left");
}

AvlNode* rotate_right(AvlNode* root) {
    (void)root; // 实现后可移除这行占位语句。
    // TODO: AVL 单旋与双旋，参见 ../problems/q05.md
    todo("rotate_right");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        auto check = [&](AvlNode* root,const std::vector<int>& expected) {
            std::vector<int> values; std::unordered_set<AvlNode*> visited;
            std::function<int(AvlNode*)> inspect = [&](AvlNode* node) {
                if (!node) return 0;
                require(visited.insert(node).second,"rotation must not create cycle/shared node");
                const int left_height = inspect(node->left);
                values.push_back(node->value);
                const int right_height = inspect(node->right);
                practice_test::equal(node->height,1+std::max(left_height,right_height),"updated height");
                require(left_height-right_height <= 1 && right_height-left_height <= 1,"balanced result");
                return 1+std::max(left_height,right_height);
            };
            inspect(root); practice_test::equal(values,expected,"BST order and no lost node");
        };
        {
            AvlNode a{1}, b{2,&a,nullptr,2}, c{3,&b,nullptr,3};
            AvlNode* result = rotate_right(&c);
            require(result == &b && b.left == &a && b.right == &c,"LL node identity");
            check(result,{1,2,3});
        }
        {
            AvlNode c{3}, b{2,nullptr,&c,2}, a{1,nullptr,&b,3};
            AvlNode* result = rotate_left(&a);
            require(result == &b && b.left == &a && b.right == &c,"RR node identity");
            check(result,{1,2,3});
        }
        {
            AvlNode n10{10}, n20{20,&n10,nullptr,2}, n40{40}, n60{60};
            AvlNode n30{30,&n20,&n40,3}, n50{50,&n30,&n60,4};
            AvlNode* result = rotate_right(&n50);
            require(result == &n30 && n50.left == &n40,"right rotation transfers middle subtree");
            check(result,{10,20,30,40,50,60});
        }
        {
            AvlNode n20{20}, n40{40}, n70{70}, n60{60,nullptr,&n70,2};
            AvlNode n50{50,&n40,&n60,3}, n30{30,&n20,&n50,4};
            AvlNode* result = rotate_left(&n30);
            require(result == &n50 && n30.right == &n40,"left rotation transfers middle subtree");
            check(result,{20,30,40,50,60,70});
        }
        {
            AvlNode n10{10}, n30{30}, n45{45}, n60{60};
            AvlNode n40{40,&n30,&n45,2}, n20{20,&n10,&n40,3}, n50{50,&n20,&n60,4};
            n50.left = rotate_left(n50.left);
            AvlNode* result = rotate_right(&n50);
            require(result == &n40 && n20.right == &n30 && n50.left == &n45,"LR middle subtrees");
            check(result,{10,20,30,40,45,50,60});
        }
        {
            AvlNode n10{10}, n25{25}, n40{40}, n60{60};
            AvlNode n30{30,&n25,&n40,2}, n50{50,&n30,&n60,3}, n20{20,&n10,&n50,4};
            n20.right = rotate_right(n20.right);
            AvlNode* result = rotate_left(&n20);
            require(result == &n30 && n20.right == &n25 && n50.left == &n40,"RL middle subtrees");
            check(result,{10,20,25,30,40,50,60});
        }
    });
}
