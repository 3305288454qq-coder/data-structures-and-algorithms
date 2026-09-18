// S04 链队列
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

void enqueue_linked(LinkedQueue& queue, int value) {
    (void)queue; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 链队列，参见 ../problems/s04.md
    todo("enqueue_linked");
}

bool dequeue_linked(LinkedQueue& queue, int& value) {
    (void)queue; // 实现后可移除这行占位语句。
    (void)value; // 实现后可移除这行占位语句。
    // TODO: 链队列，参见 ../problems/s04.md
    todo("dequeue_linked");
}

void clear_queue(LinkedQueue& queue) {
    (void)queue; // 实现后可移除这行占位语句。
    // TODO: 链队列，参见 ../problems/s04.md
    todo("clear_queue");
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        LinkedQueue queue; int value = 0;
        require(!dequeue_linked(queue,value), "empty");
        enqueue_linked(queue,10);
        require(queue.front != nullptr && queue.front == queue.rear && queue.rear->next == nullptr, "singleton endpoints");
        enqueue_linked(queue,20); practice_test::equal(list_values(queue.front), std::vector<int>({10,20}), "queue links");
        require(queue.rear == queue.front->next && queue.rear->next == nullptr, "tail endpoint");
        require(dequeue_linked(queue,value), "dequeue first"); practice_test::equal(value,10,"FIFO");
        require(dequeue_linked(queue,value), "dequeue last"); practice_test::equal(value,20,"last value");
        require(queue.front == nullptr && queue.rear == nullptr, "both endpoints empty");
        enqueue_linked(queue,30); enqueue_linked(queue,40); clear_queue(queue);
        require(queue.front == nullptr && queue.rear == nullptr, "clear endpoints");
        clear_queue(queue); enqueue_linked(queue,50); require(dequeue_linked(queue,value), "reuse after clear"); practice_test::equal(value,50,"reuse");
    });
}
