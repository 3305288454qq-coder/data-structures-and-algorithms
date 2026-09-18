#pragma once
#include "common.hpp"
#include <functional>
#include <unordered_set>

// 自动测试只判断这里列出的用例；通过不代表已掌握或完成在线判题。
namespace practice_test {
inline std::size_t checks = 0;
inline void require(bool condition, const std::string& label) {
    ++checks;
    if (!condition) throw std::runtime_error("FAIL: " + label);
}
template<class Actual, class Expected>
void equal(const Actual& actual, const Expected& expected, const std::string& label) {
    require(actual == expected, label);
}
template<class Function>
int run(Function test) {
    checks = 0;
    try {
        test();
        if (checks == 0) throw std::runtime_error("FAIL: no assertions executed");
        std::cout << "PASS: " << checks << " checks\n";
        return 0;
    } catch (const std::exception& error) {
        const std::string message(error.what());
        std::cerr << message << '\n';
        return message.rfind("TODO: implement ", 0) == 0 ? 2 : 1;
    } catch (...) {
        std::cerr << "FAIL: unknown exception\n";
        return 1;
    }
}
inline std::vector<int> list_values(const ListNode* head) {
    std::vector<int> values;
    std::unordered_set<const ListNode*> seen;
    while (head) {
        require(seen.insert(head).second, "list must not contain a cycle");
        values.push_back(head->value);
        head = head->next;
    }
    return values;
}
inline std::vector<int> tree_values(const TreeNode* root) {
    std::vector<int> values;
    std::unordered_set<const TreeNode*> seen;
    std::function<void(const TreeNode*)> visit = [&](const TreeNode* node) {
        if (!node) return;
        require(seen.insert(node).second, "tree links must not repeat nodes");
        visit(node->left);
        values.push_back(node->value);
        visit(node->right);
    };
    visit(root);
    return values;
}
inline void triples_equal(const std::vector<Triple>& actual, const std::vector<Triple>& expected, const std::string& label) {
    practice_test::equal(actual.size(), expected.size(), label + " size");
    for (std::size_t i = 0; i < actual.size(); ++i) {
        require(actual[i].row == expected[i].row && actual[i].col == expected[i].col &&
                actual[i].value == expected[i].value, label + " entry " + std::to_string(i));
    }
}
inline void topological(const std::vector<std::vector<int>>& graph, const std::vector<int>& order) {
    practice_test::equal(order.size(), graph.size(), "topological length");
    std::vector<int> position(graph.size(), -1);
    for (std::size_t i = 0; i < order.size(); ++i) {
        require(order[i] >= 0 && static_cast<std::size_t>(order[i]) < graph.size(), "topological vertex range");
        require(position[order[i]] == -1, "topological vertices unique");
        position[order[i]] = static_cast<int>(i);
    }
    for (std::size_t from = 0; from < graph.size(); ++from)
        for (int to : graph[from])
            require(position[from] < position[to], "topological edge direction");
}
}

