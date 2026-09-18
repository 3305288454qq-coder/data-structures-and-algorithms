#pragma once
#include <algorithm>
#include <array>
#include <cstddef>
#include <exception>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// 这些是数据类型和测试辅助设施；目标算法留在各练习文件中实现。
constexpr int CAPACITY = 1000;
constexpr long long INF = std::numeric_limits<long long>::max() / 4;
struct SqList { std::array<int, CAPACITY> data{}; int length = 0; };
struct ListNode { int value = 0; ListNode* next = nullptr; };
struct DoubleNode { int value = 0; DoubleNode* prev = nullptr; DoubleNode* next = nullptr; };
struct ArrayStack { std::array<int, CAPACITY> data{}; int top = 0; };
struct RingQueue { std::array<int, CAPACITY> data{}; int front = 0; int rear = 0; };
struct LinkedQueue { ListNode* front = nullptr; ListNode* rear = nullptr; };
struct Triple { int row = 0; int col = 0; int value = 0; };
struct TreeNode { int value = 0; TreeNode* left = nullptr; TreeNode* right = nullptr; };
struct ThreadNode {
    int value = 0; ThreadNode* left = nullptr; ThreadNode* right = nullptr;
    bool ltag = false; bool rtag = false;
};
struct AvlNode {
    int value = 0; AvlNode* left = nullptr; AvlNode* right = nullptr; int height = 1;
};
struct Edge { int from = 0; int to = 0; long long weight = 0; };

[[noreturn]] inline void todo(const char* name) {
    throw std::logic_error(std::string("TODO: implement ") + name);
}
template <class Range>
void print_range(const Range& values) {
    bool first = true;
    for (const auto& value : values) {
        if (!first) std::cout << ' ';
        std::cout << value;
        first = false;
    }
    std::cout << '\n';
}
