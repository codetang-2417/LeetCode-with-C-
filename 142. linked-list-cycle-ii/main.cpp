#include <iostream>

/*
 * 142. 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;

        while(fastPtr!=nullptr||fastPtr->next!= nullptr){//如果没有环，提前到达结尾
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(fastPtr == slowPtr){
                break;
            }
        }
        ListNode* temp = head;
        if(fastPtr!= nullptr){//有环
            while(temp != fastPtr){
                temp = temp->next;
                fastPtr = fastPtr->next;
            }
        }
        return fastPtr;
    }
};

int main() {
    ListNode* head = new ListNode(3,new ListNode(2,new ListNode(0,new ListNode(-4))));
    head->next->next->next->next = head->next;
    Solution sol;
    sol.detectCycle(head);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
