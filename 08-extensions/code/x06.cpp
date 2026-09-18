// X06 Trie：单词与前缀查询 — 核心算法由学习者实现。
#include "../../templates/common.hpp"
#include "../../templates/test_support.hpp"

struct TrieNode {
    std::array<int, 26> child;
    bool word = false;
    TrieNode() { child.fill(-1); }
};
struct Trie { std::vector<TrieNode> nodes{TrieNode{}}; };

void trie_insert(Trie& trie, const std::string& word) {
    (void)trie;
    (void)word;
    todo("trie_insert");
}

bool trie_contains(const Trie& trie, const std::string& word) {
    (void)trie;
    (void)word;
    todo("trie_contains");
}

bool trie_has_prefix(const Trie& trie, const std::string& prefix) {
    (void)trie;
    (void)prefix;
    todo("trie_has_prefix");
}

int main() {
    return practice_test::run([] {
        namespace pt = practice_test;
        Trie trie;
        pt::require(!trie_contains(trie,""), "empty word initially absent");
        pt::require(trie_has_prefix(trie,""), "empty prefix");
        trie_insert(trie,"cat"); trie_insert(trie,"car"); trie_insert(trie,"cat");
        pt::require(trie_contains(trie,"cat"), "word cat");
        pt::require(!trie_contains(trie,"ca"), "prefix is not word");
        pt::require(trie_has_prefix(trie,"ca"), "prefix ca");
        pt::require(!trie_has_prefix(trie,"dog"), "missing prefix");
        trie_insert(trie,"");
        pt::require(trie_contains(trie,""), "insert empty word");
    });
}
