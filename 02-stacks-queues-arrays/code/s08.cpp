// S08 稀疏矩阵转置
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

std::vector<Triple> transpose_sparse(int rows, int cols, const std::vector<Triple>& entries) {
    (void)rows; // 实现后可移除这行占位语句。
    (void)cols; // 实现后可移除这行占位语句。
    (void)entries; // 实现后可移除这行占位语句。
    // TODO: 稀疏矩阵转置，参见 ../problems/s08.md
    todo("transpose_sparse");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        triples_equal(transpose_sparse(2,3,{{0,1,5},{1,0,7}}), {{0,1,7},{1,0,5}}, "sample");
        triples_equal(transpose_sparse(4,7,{}), {}, "zero matrix");
        triples_equal(transpose_sparse(1,6,{{0,0,4},{0,5,-2}}), {{0,0,4},{5,0,-2}}, "single row");
        const std::vector<Triple> entries{{0,9,1},{2,0,2},{2,9,3},{4,4,4}};
        auto once = transpose_sparse(5,12,entries);
        triples_equal(once, {{0,2,2},{4,4,4},{9,0,1},{9,2,3}}, "empty rows and columns");
        triples_equal(transpose_sparse(12,5,once), entries, "transpose twice");
    });
}
