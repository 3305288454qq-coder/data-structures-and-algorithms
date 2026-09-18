// B07 并查集
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

int find_root(std::vector<int>& parent, int node) {
    (void)parent; // 实现后可移除这行占位语句。
    (void)node; // 实现后可移除这行占位语句。
    // TODO: 并查集，参见 ../problems/b07.md
    todo("find_root");
}

void unite(std::vector<int>& parent, int a, int b) {
    (void)parent; // 实现后可移除这行占位语句。
    (void)a; // 实现后可移除这行占位语句。
    (void)b; // 实现后可移除这行占位语句。
    // TODO: 并查集，参见 ../problems/b07.md
    todo("unite");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        std::vector<int> parent{0,1,2,3,4};
        for (int i = 0; i < 5; ++i) practice_test::equal(find_root(parent,i),i,"initial roots");
        unite(parent,0,1); unite(parent,1,2);
        practice_test::equal(find_root(parent,0),find_root(parent,2),"transitive union");
        require(find_root(parent,0) != find_root(parent,3),"separate components");
        unite(parent,0,2); unite(parent,3,3);
        practice_test::equal(find_root(parent,0),find_root(parent,2),"repeat union"); practice_test::equal(find_root(parent,3),3,"self union");
        unite(parent,3,4); unite(parent,2,4);
        const int root = find_root(parent,0);
        for (int i = 0; i < 5; ++i) practice_test::equal(find_root(parent,i),root,"connected");
        std::vector<int> chain{1,2,3,4,4};
        practice_test::equal(find_root(chain,0),4,"chain root");
        for (int p : chain) require(p >= 0 && p < 5,"parent remains valid");
    });
}
