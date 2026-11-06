 // S12 三角矩阵与三对角矩阵地址映射
#include "../../templates/test_support.hpp"

#include <cstdlib>
int lower_index(int row, int col, int n) {
    if (n < 1 || n > 10000)
    {
        throw std::out_of_range("matirx size out of range");
    }
    else if (row >= 0 && row < n && col >= 0 && col < n)
    {
        if (row >= col)
        {
            return row * (row + 1) / 2 + col;
        }
        else return -1;
    }
    throw std::out_of_range("over matrix");
}
int tri_index(int row, int col, int n) {
    if (n < 1 || n > 10000)
        throw std::out_of_range("matirx size out of range");
    else if (row >= 0 && row < n && col >= 0 && col < n)
    {
        if (std::abs(row - col) <= 1)
        {
            return 2 * row + col;
        }
        else return -1;
    }
    throw std::out_of_range("over matrix");
}

int main() { return practice_test::run([] {
    int expected=0;
    for(int row=0;row<4;++row) for(int col=0;col<=row;++col)
        practice_test::equal(lower_index(row,col,4),expected++,"lower row-major order");
    practice_test::equal(lower_index(0,3,4),-1,"upper region not stored");
    expected=0;
    for(int row=0;row<4;++row) for(int col=0;col<4;++col)
        if(std::abs(row-col)<=1) practice_test::equal(tri_index(row,col,4),expected++,"tridiagonal row-major order");
        else practice_test::equal(tri_index(row,col,4),-1,"zero region");
    practice_test::equal(lower_index(0,0,1),0,"single lower");
    practice_test::equal(tri_index(0,0,1),0,"single tri");
    bool rejected=false; try { tri_index(-1,0,4); } catch(const std::out_of_range&) { rejected=true; }
    practice_test::require(rejected,"invalid coordinate");
    rejected=false; try { lower_index(0,4,4); } catch(const std::out_of_range&) { rejected=true; }
    practice_test::require(rejected,"invalid column");
}); }
