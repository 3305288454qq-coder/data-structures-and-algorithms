// S03 循环队列
// 这是可编译的练习框架；TODO 抛出异常表示尚未实现，不代表测试通过。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

bool enqueue(RingQueue& queue, int value) {
    if (queue.front == (queue.rear + 1) % CAPACITY) return false;
    queue.data[queue.rear] = value;
    queue.rear = (queue.rear + 1) % CAPACITY;
    return true;    
}

bool dequeue(RingQueue& queue, int& value) {
    if (queue.front == queue.rear) return false;
    value = queue.data[queue.front];
    queue.front = (queue.front + 1) % CAPACITY;
    return true;    
}

int queue_size(const RingQueue& queue) {
    return (queue.rear - queue.front + CAPACITY) % CAPACITY;
}

// 自动比较普通与边界用例；目标函数仍由学习者实现。
int main() {
    return practice_test::run([] {
        using practice_test::require;
        using practice_test::list_values;
        using practice_test::tree_values;
        using practice_test::triples_equal;
        using practice_test::topological;
        RingQueue queue; int value = 0;
        practice_test::equal(queue_size(queue), 0, "empty size"); require(!dequeue(queue,value), "empty dequeue");
        for (int i = 0; i < CAPACITY-1; ++i) require(enqueue(queue,i), "fill queue");
        practice_test::equal(queue_size(queue), CAPACITY-1, "usable capacity"); require(!enqueue(queue,-1), "reject full");
        for (int i = 0; i < CAPACITY/2; ++i) { require(dequeue(queue,value), "partial drain"); practice_test::equal(value,i,"FIFO first half"); }
        for (int i = 0; i < CAPACITY/2; ++i) require(enqueue(queue,CAPACITY-1+i), "wrap enqueue");
        practice_test::equal(queue_size(queue), CAPACITY-1, "wrapped full size");
        for (int i = CAPACITY/2; i < CAPACITY-1+CAPACITY/2; ++i) { require(dequeue(queue,value), "wrapped drain"); practice_test::equal(value,i,"FIFO after wrap"); }
        practice_test::equal(queue_size(queue), 0, "drained"); require(!dequeue(queue,value), "empty after wrap");
    });
}
