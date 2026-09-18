// Q07 开放定址：线性探测与删除标记 — 核心算法保留 TODO。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"
#include <functional>
#include <set>
#include <memory>
namespace pt = practice_test;


enum class SlotState { Empty, Occupied, Deleted };
struct HashSlot { int key=0; SlotState state=SlotState::Empty; };
struct HashTable { std::vector<HashSlot> slots; };
int hash_find(const HashTable& table, int key) {
    (void)table; (void)key; todo("hash_find");
}
bool hash_insert(HashTable& table, int key) {
    (void)table; (void)key; todo("hash_insert");
}
bool hash_erase(HashTable& table, int key) {
    (void)table; (void)key; todo("hash_erase");
}
int main() { return pt::run([] {
    HashTable t{std::vector<HashSlot>(5)};
    for(int value: {1,6,11}) pt::require(hash_insert(t,value),"insert collisions");
    pt::equal(hash_find(t,11),3,"collision location");
    pt::require(hash_erase(t,6),"delete middle");
    pt::require(t.slots[2].state==SlotState::Deleted,"must leave tombstone");
    pt::equal(hash_find(t,11),3,"search past deleted");
    pt::require(!hash_insert(t,11),"duplicate after tombstone");
    pt::require(hash_insert(t,16),"reuse tombstone");
    pt::equal(hash_find(t,16),2,"first tombstone reused");
    pt::require(!hash_erase(t,99),"delete missing");
    pt::require(hash_insert(t,0) && hash_insert(t,4),"fill table");
    pt::require(!hash_insert(t,9),"full table ends");
    pt::equal(hash_find(t,9),-1,"missing in full table");
    HashTable negative{std::vector<HashSlot>(7)};
    pt::require(hash_insert(negative,-1),"negative key");
    pt::equal(hash_find(negative,-1),6,"nonnegative modulo");
    pt::require(hash_insert(negative,std::numeric_limits<int>::min()),"int minimum");
    pt::require(hash_find(negative,std::numeric_limits<int>::min())>=0,"minimum found");
    HashTable empty;
    pt::require(!hash_insert(empty,1) && !hash_erase(empty,1),"zero capacity");
    pt::equal(hash_find(empty,1),-1,"zero capacity find");
}); }
