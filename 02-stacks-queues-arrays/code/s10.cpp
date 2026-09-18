// S10 循环数组双端队列
#include "../../templates/test_support.hpp"

struct ArrayDeque { std::vector<int> storage; std::size_t front=0; std::size_t count=0; };
bool deque_push_front(ArrayDeque& q, int value) {
    (void)q;
    (void)value;
    todo("deque_push_front");
}
bool deque_push_back(ArrayDeque& q, int value) {
    (void)q;
    (void)value;
    todo("deque_push_back");
}
bool deque_pop_front(ArrayDeque& q, int& out) {
    (void)q;
    (void)out;
    todo("deque_pop_front");
}
bool deque_pop_back(ArrayDeque& q, int& out) {
    (void)q;
    (void)out;
    todo("deque_pop_back");
}

int main() { return practice_test::run([] {
    ArrayDeque q{std::vector<int>(3),0,0}; int out=91;
    practice_test::require(!deque_pop_front(q,out) && out==91,"empty");
    practice_test::require(deque_push_back(q,2) && deque_push_front(q,1) && deque_push_back(q,3),"fill both ends");
    practice_test::require(!deque_push_front(q,0) && !deque_push_back(q,4),"full");
    practice_test::require(deque_pop_front(q,out) && out==1,"front value");
    practice_test::require(deque_push_back(q,4),"wrap push");
    practice_test::require(deque_pop_back(q,out) && out==4,"wrapped back");
    practice_test::require(deque_pop_back(q,out) && out==3,"back order");
    practice_test::require(deque_pop_front(q,out) && out==2 && q.count==0,"last item");
    ArrayDeque single{std::vector<int>(1),0,0};
    practice_test::require(deque_push_front(single,8) && !deque_push_back(single,9),"capacity one");
    practice_test::require(deque_pop_back(single,out) && out==8,"capacity one removal");
    ArrayDeque zero;
    practice_test::require(!deque_push_front(zero,1) && !deque_push_back(zero,1),"zero capacity");
    out=73;
    practice_test::require(!deque_pop_front(zero,out) && !deque_pop_back(zero,out) && out==73,"zero capacity removal");
}); }
