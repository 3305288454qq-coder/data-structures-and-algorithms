// B10 孩子兄弟表示与森林双向转换
#include "../../templates/test_support.hpp"

struct Forest { std::vector<std::vector<int>> children; std::vector<int> roots; };
struct SiblingLinks { int first_child=-1; int next_sibling=-1; };
std::vector<SiblingLinks> to_siblings(const Forest& forest) {
    (void)forest;
    todo("to_siblings");
}
Forest from_siblings(const std::vector<SiblingLinks>& links, int first_root) {
    (void)links;
    (void)first_root;
    todo("from_siblings");
}

int main() { return practice_test::run([] {
    const Forest forest{{{1,2},{},{3},{},{5},{}},{0,4}};
    const auto links=to_siblings(forest);
    const std::vector<SiblingLinks> expected{{1,4},{-1,2},{3,-1},{-1,-1},{5,-1},{-1,-1}};
    practice_test::equal(links.size(),expected.size(),"node count");
    for(std::size_t i=0;i<links.size();++i) {
        practice_test::equal(links[i].first_child,expected[i].first_child,"first child");
        practice_test::equal(links[i].next_sibling,expected[i].next_sibling,"next sibling");
    }
    auto restored=from_siblings(links,0);
    practice_test::equal(restored.children,forest.children,"restore every child list");
    practice_test::equal(restored.roots,forest.roots,"restore root order");
    practice_test::require(to_siblings(Forest{}).empty(),"empty encode");
    restored=from_siblings({},-1);
    practice_test::require(restored.children.empty() && restored.roots.empty(),"empty decode");
    const Forest single{{{}},{0}};
    restored=from_siblings(to_siblings(single),0);
    practice_test::equal(restored.children,single.children,"single tree");
}); }
