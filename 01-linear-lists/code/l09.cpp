// L09 动态顺序表与按值查找
// TODO 表示尚未实现；自动测试通过也不直接表示已掌握。
#include "../../templates/test_support.hpp"

struct DynamicList { std::vector<int> storage; int length = 0; };
int locate_value(const DynamicList& list, int value) {
    (void)list;
    (void)value;
    todo("locate_value");
}
bool insert_dynamic(DynamicList& list, int position, int value) {
    (void)list;
    (void)position;
    (void)value;
    todo("insert_dynamic");
}

int main() { return practice_test::run([] {
    DynamicList list;
    practice_test::equal(locate_value(list, 8), 0, "empty lookup");
    practice_test::require(!insert_dynamic(list, 0, 9), "invalid insertion");
    for (int i = 1; i <= 33; ++i) practice_test::require(insert_dynamic(list, i, i), "append");
    practice_test::equal(list.length, 33, "logical length");
    practice_test::require(list.storage.size() >= 33, "capacity");
    for (int i = 0; i < 33; ++i) practice_test::equal(list.storage[i], i + 1, "growth preserves data");
    practice_test::require(insert_dynamic(list, 1, 7), "front insertion");
    practice_test::equal(locate_value(list, 7), 1, "first matching position");
    const auto before = list.storage;
    practice_test::require(!insert_dynamic(list, 36, 5), "out of range");
    practice_test::equal(list.storage, before, "invalid call preserves storage");
}); }
