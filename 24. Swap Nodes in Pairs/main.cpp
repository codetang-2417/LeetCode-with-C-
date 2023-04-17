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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *last = cur->next->next->next;//保存后续结点
            ListNode *temp = cur->next->next;//保存第二个结点
            cur->next->next->next = cur->next;//第二个结点指向第一个结点
            cur->next->next = last;//第一个结点指向剩下的结点
            cur->next = temp;//头结点指向第二个结点
            cur = temp->next;//指向第二个结点作为下一个交换的虚拟头结点
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {
    Solution sol;
    auto *head = new ListNode(0, new ListNode(1, new ListNode(2, nullptr)));
    head = sol.swapPairs(head);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
