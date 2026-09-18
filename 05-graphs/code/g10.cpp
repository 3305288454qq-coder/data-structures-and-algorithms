// G10 邻接矩阵与两种存储的转换 — 核心留给学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
namespace pt = practice_test;


std::vector<std::vector<int>> make_matrix(int n, const std::vector<std::pair<int,int>>& edges) {
    (void)n; (void)edges; todo("make_matrix");
}
std::vector<std::vector<int>> matrix_to_list(const std::vector<std::vector<int>>& matrix) {
    (void)matrix; todo("matrix_to_list");
}
int main() { return pt::run([] {
    const std::vector<std::vector<int>> expected{{0,1,1},{0,0,0},{0,0,1}};
    pt::equal(make_matrix(3, {{0,2},{0,1},{0,2},{2,2}}), expected, "directed/self-loop/duplicate");
    pt::equal(matrix_to_list(expected), std::vector<std::vector<int>>{{1,2},{},{2}}, "ordered adjacency");
    pt::equal(make_matrix(0, {}), std::vector<std::vector<int>>{}, "empty matrix");
    pt::equal(matrix_to_list({}), std::vector<std::vector<int>>{}, "empty list");
    pt::equal(make_matrix(2, {}), std::vector<std::vector<int>>{{0,0},{0,0}}, "isolated vertices");
    pt::equal(matrix_to_list({{0}}), std::vector<std::vector<int>>{{}}, "single vertex");
}); }
