// L01 顺序表基本操作
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

bool get_element(const SqList& list, int position, int& value) {
    (void)list; // 实现后可移除这行占位语句。
    (void)position; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 顺序表基本操作，参见 ../problems/l01.md
    todo("get_element");
}

bool insert_element(SqList& list, int position, int value) {
    (void)list; // 实现后可移除这行占位语句。
    (void)position; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 顺序表基本操作，参见 ../problems/l01.md
    todo("insert_element");
}

bool erase_element(SqList& list, int position, int& removed) {
    (void)list; // 实现后可移除这行占位语句。
    (void)position; // 实现后可移除这行占位语句。
    (void)removed; // 实现后可移除这行占位语句。
    // TODO: 顺序表基本操作，参见 ../problems/l01.md
    todo("erase_element");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        SqList list; int out = 99;
        require(!get_element(list, 1, out), "empty get");
        require(!erase_element(list, 1, out), "empty erase");
        require(!insert_element(list, 0, 9), "zero position rejected");
        require(insert_element(list, 1, 10), "insert empty");
        require(insert_element(list, 2, 30), "insert tail");
        require(insert_element(list, 2, 20), "insert middle");
        practice_test::equal(list.length, 3, "length after insertion");
        require(get_element(list, 2, out), "get middle"); practice_test::equal(out, 20, "middle value");
        const auto before = list.data;
        require(!insert_element(list, 5, 50), "past end rejected");
        require(!erase_element(list, 0, out), "invalid erase rejected");
        practice_test::equal(list.data, before, "invalid operation preserves data");
        practice_test::equal(list.length, 3, "invalid operation preserves length");
        require(erase_element(list, 1, out), "erase head"); practice_test::equal(out, 10, "removed head");
        require(erase_element(list, 2, out), "erase tail"); practice_test::equal(out, 30, "removed tail");
        require(erase_element(list, 1, out), "erase singleton"); practice_test::equal(list.length, 0, "empty again");
        for (int i = 0; i < CAPACITY; ++i) require(insert_element(list, i + 1, i), "fill capacity");
        const auto full = list.data;
        require(!insert_element(list, 1, -1), "full insert rejected");
        practice_test::equal(list.data, full, "full insert preserves data");
        practice_test::equal(list.length, CAPACITY, "full length");
    });
}
