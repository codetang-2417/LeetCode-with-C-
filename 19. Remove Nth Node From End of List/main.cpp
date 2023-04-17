#include <iostream>

/**
 * Definition for singly-linked list.
 *
 */
/*
 * 24. 两两交换链表中的节点
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
