#include <iostream>

/*
 * 19. 删除链表的倒数第 N 个结点
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode temp(0, head);
        ListNode *dummy = &temp;
        ListNode *fastPtr = dummy, *slowPtr = dummy;

        while (fastPtr != nullptr) {
            if (n < 0) {
                slowPtr = slowPtr->next;
            } else {
                n--;
            }
            fastPtr = fastPtr->next;
        }
        if (slowPtr->next != nullptr) {
            ListNode *delNode = slowPtr->next;
            slowPtr->next = slowPtr->next->next;
            delete delNode;
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
