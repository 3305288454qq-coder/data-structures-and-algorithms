// L14 回文链表与结构恢复
// TODO 表示尚未实现；自动测试通过也不直接表示已掌握。
#include "../../templates/test_support.hpp"

bool is_palindrome_restoring(ListNode* head) {
    (void)head;
    todo("is_palindrome_restoring");
}

int main() { return practice_test::run([] {
    practice_test::require(is_palindrome_restoring(nullptr),"empty");
    for (const auto& values : std::vector<std::vector<int>>{{1},{1,2,1},{1,2,2,1},{1,2,3,1},{1,2}}) {
        std::vector<ListNode> nodes(values.size());
        for(std::size_t i=0;i<nodes.size();++i) nodes[i]={values[i],i+1<nodes.size()?&nodes[i+1]:nullptr};
        const bool expected=std::equal(values.begin(),values.end(),values.rbegin());
        practice_test::equal(is_palindrome_restoring(&nodes[0]),expected,"palindrome result");
        for(std::size_t i=0;i<nodes.size();++i) {
            practice_test::equal(nodes[i].value,values[i],"value preserved");
            practice_test::require(nodes[i].next==(i+1<nodes.size()?&nodes[i+1]:nullptr),"every link restored");
        }
    }
}); }
