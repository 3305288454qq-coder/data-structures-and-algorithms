// S07 对称矩阵压缩存储
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::size_t symmetric_index(int i, int j) {
    std::size_t row = static_cast<std::size_t>(i);
    std::size_t col = static_cast<std::size_t>(j);
    if (i >= j)
    {
        return row * (row + 1) / 2 + col;
    }
    else
    {
        return col * (col + 1) / 2 + row;
    }
}

int symmetric_get(const std::vector<int>& lower, int i, int j) {
    return lower[symmetric_index(i, j)];
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(symmetric_index(0,0), std::size_t{0}, "singleton index");
        practice_test::equal(symmetric_get({7},0,0), 7, "singleton value");
        const std::vector<int> lower{10,20,30,40,50,60};
        const int expected[3][3] = {{10,20,40},{20,30,50},{40,50,60}};
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            practice_test::equal(symmetric_get(lower,i,j), expected[i][j], "symmetric cell");
            practice_test::equal(symmetric_index(i,j), symmetric_index(j,i), "mirror shares storage");
        }
        practice_test::equal(symmetric_index(0,2), std::size_t{3}, "upper right");
        practice_test::equal(symmetric_index(2,2), std::size_t{5}, "last diagonal");
    });
}
