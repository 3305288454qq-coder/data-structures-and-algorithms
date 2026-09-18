// S09 共享栈：两端增长与判满
#include "../../templates/test_support.hpp"

struct SharedStack { std::array<int,6> data{}; int top_left=-1; int top_right=6; };
bool shared_push(SharedStack& stacks, int side, int value) {
    (void)stacks;
    (void)side;
    (void)value;
    todo("shared_push");
}
bool shared_pop(SharedStack& stacks, int side, int& out) {
    (void)stacks;
    (void)side;
    (void)out;
    todo("shared_pop");
}

int main() { return practice_test::run([] {
    SharedStack s; int out=99;
    practice_test::require(!shared_pop(s,0,out) && out==99,"empty left preserves output");
    practice_test::require(!shared_pop(s,1,out) && out==99,"empty right preserves output");
    for(int i=1;i<=3;++i) { practice_test::require(shared_push(s,0,i),"left push"); practice_test::require(shared_push(s,1,10+i),"right push"); }
    practice_test::require(!shared_push(s,0,7) && !shared_push(s,1,8),"shared full");
    for(int i=3;i>=1;--i) {
        practice_test::require(shared_pop(s,0,out) && out==i,"left LIFO");
        practice_test::require(shared_pop(s,1,out) && out==10+i,"right LIFO");
    }
    for(int i=0;i<6;++i) practice_test::require(shared_push(s,0,i),"left uses entire storage");
    practice_test::require(!shared_push(s,1,9),"no hidden reserved half");
    bool rejected=false; try { shared_push(s,2,1); } catch(const std::invalid_argument&) { rejected=true; }
    practice_test::require(rejected,"invalid side");
}); }
