// B12 并查集：按大小合并与路径压缩
#include "../../templates/test_support.hpp"

struct WeightedDsu { std::vector<int> parent; std::vector<int> size; };
int find_compress(WeightedDsu& dsu, int node) {
    (void)dsu;
    (void)node;
    todo("find_compress");
}
bool unite_by_size(WeightedDsu& dsu, int a, int b) {
    (void)dsu;
    (void)a;
    (void)b;
    todo("unite_by_size");
}

int main() { return practice_test::run([] {
    WeightedDsu d{{0,1,2,3,4,5},{1,1,1,1,1,1}};
    practice_test::require(unite_by_size(d,0,1),"first merge");
    practice_test::require(unite_by_size(d,2,3),"second merge");
    practice_test::require(unite_by_size(d,0,2),"equal-size merge");
    const int large=find_compress(d,0);
    practice_test::require(unite_by_size(d,4,0),"smaller into larger");
    practice_test::equal(find_compress(d,4),large,"larger root retained");
    practice_test::equal(d.size[large],5,"root size");
    practice_test::require(!unite_by_size(d,1,4),"duplicate merge");
    practice_test::equal(d.size[large],5,"duplicate preserves size");
    practice_test::require(find_compress(d,5)!=large,"isolated component");
    WeightedDsu chain{{0,0,1,2},{4,1,1,1}};
    practice_test::equal(find_compress(chain,3),0,"find root");
    practice_test::equal(chain.parent[3],0,"path compressed");
    bool rejected=false; try { find_compress(d,6); } catch(const std::out_of_range&) { rejected=true; }
    practice_test::require(rejected,"invalid node");
}); }
