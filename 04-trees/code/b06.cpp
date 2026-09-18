// B06 哈夫曼树与带权路径长度
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

long long huffman_wpl(const std::vector<int>& weights) {
    (void)weights; // 实现后可移除这行占位语句。
    // TODO: 哈夫曼树与带权路径长度，参见 ../problems/b06.md
    todo("huffman_wpl");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        practice_test::equal(huffman_wpl({2,3,7}),17LL,"sample");
        practice_test::equal(huffman_wpl({9}),0LL,"singleton depth zero");
        practice_test::equal(huffman_wpl({5,5}),10LL,"two weights");
        practice_test::equal(huffman_wpl({1,1,1,1}),8LL,"equal weights");
        practice_test::equal(huffman_wpl({1,2,3,4,5}),33LL,"unequal weights");
        practice_test::equal(huffman_wpl({2000000000,2000000000,2000000000}),10000000000LL,"sum exceeds int");
    });
}
