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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0,head);
        ListNode* fastNode = dummyHead;
        ListNode* slowNode = dummyHead;

        while(fastNode->next != nullptr){//fastNode指向最后一个结点的时候，slowNode应该指向倒数第n+1个结点
            fastNode = fastNode->next;
            if(n==0){//当快指针已经走完n+1的时候，慢指针才开始走
                slowNode = slowNode->next;
            }
            else
                n--;
        }
        //此时应当有n==0，也就是f移动到最后时，s也移动到倒数n+1，如果n>0，则没有删除
        if(!n){
            ListNode* temp = slowNode->next;
            slowNode->next = slowNode->next->next;
            delete temp;
        }

        ListNode* temp = dummyHead;
        head = dummyHead->next;
        delete temp;
        return head;
    }
};


int main() {
    ListNode* head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));

    Solution sol;
    sol.removeNthFromEnd(head,2);
    while(head!= nullptr){
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}
