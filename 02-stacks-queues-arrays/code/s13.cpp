// S13 稀疏矩阵快速转置
#include "../../templates/test_support.hpp"

std::vector<Triple> fast_transpose(const std::vector<Triple>& entries, int rows, int cols) {
    (void)entries;
    (void)rows;
    (void)cols;
    todo("fast_transpose");
}

int main() { return practice_test::run([] {
    const std::vector<Triple> a{{0,5,7},{1,0,-2},{1,5,3},{2,2,4}};
    const std::vector<Triple> expected{{0,1,-2},{2,2,4},{5,0,7},{5,1,3}};
    auto result=fast_transpose(a,3,6);
    practice_test::triples_equal(result,expected,"rectangular transpose with empty columns");
    practice_test::triples_equal(fast_transpose(result,6,3),a,"double transpose");
    practice_test::triples_equal(a,{{0,5,7},{1,0,-2},{1,5,3},{2,2,4}},"input unchanged");
    practice_test::triples_equal(fast_transpose({},0,0),{},"zero matrix");
    practice_test::triples_equal(fast_transpose({},3,8),{},"all empty columns");
    practice_test::triples_equal(fast_transpose({{2,99,8}},4,100),{{99,2,8}},"many empty columns");
}); }
