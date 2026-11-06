// B06 哈夫曼树与带权路径长度
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
long long take_min(std::vector<long long>& values)
{
    std::size_t min_index =0;
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (values[i] < values[min_index])
        {
            min_index = i;
        }
    }
    long long min_num = values[min_index];
    values[min_index] = values.back();
    values.pop_back();
    return min_num;
}
long long huffman_wpl(const std::vector<int>& weights) {
    std::vector<long long> pending;
    for(int weight : weights)
    {
        pending.push_back(weight);
    }

    long long total = 0;

    while (pending.size() > 1)
    {
        long long a = take_min(pending);
        long long b = take_min(pending);
        long long merged = a + b;

        total += merged;
        pending.push_back(merged);
    }

    return total;
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
