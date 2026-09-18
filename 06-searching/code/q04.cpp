// Q04 散列表：拉链法
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

void hash_insert(std::vector<std::vector<int>>& buckets, int key) {
    (void)buckets; // 实现后可移除这行占位语句。
    (void)key; // 实现后可移除这行占位语句。
    // TODO: 散列表：拉链法，参见 ../problems/q04.md
    todo("hash_insert");
}

bool hash_contains(const std::vector<std::vector<int>>& buckets, int key) {
    (void)buckets; // 实现后可移除这行占位语句。
    (void)key; // 实现后可移除这行占位语句。
    // TODO: 散列表：拉链法，参见 ../problems/q04.md
    todo("hash_contains");
}

bool hash_erase(std::vector<std::vector<int>>& buckets, int key) {
    (void)buckets; // 实现后可移除这行占位语句。
    (void)key; // 实现后可移除这行占位语句。
    // TODO: 散列表：拉链法，参见 ../problems/q04.md
    todo("hash_erase");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        std::vector<std::vector<int>> buckets(5);
        require(!hash_contains(buckets,1) && !hash_erase(buckets,1),"empty buckets");
        for (int value : {1,6,-4,11,0,std::numeric_limits<int>::min(),std::numeric_limits<int>::max()}) hash_insert(buckets,value);
        hash_insert(buckets,6);
        std::size_t count = 0; for (const auto& bucket : buckets) count += bucket.size();
        practice_test::equal(count,std::size_t{7},"duplicate insertion ignored");
        for (int value : {1,6,-4,11,0,std::numeric_limits<int>::min(),std::numeric_limits<int>::max()}) require(hash_contains(buckets,value),"find key");
        require(!hash_contains(buckets,2),"missing key");
        for (int value : {6,1,-4,11}) { require(hash_erase(buckets,value),"erase collision"); require(!hash_contains(buckets,value),"removed"); }
        require(hash_contains(buckets,0),"other keys survive");
        require(!hash_erase(buckets,6),"delete missing");
        std::vector<std::vector<int>> single(1); hash_insert(single,-1); hash_insert(single,2);
        require(hash_contains(single,-1) && hash_contains(single,2),"one bucket");
        require(hash_erase(single,-1) && hash_contains(single,2),"one bucket removal");
    });
}
