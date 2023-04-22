#include <iostream>

/*
 * 02.07. 链表相交
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//数学震撼法
/*class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;
        while(A!=B){
            A = A == nullptr ? A = headB: A->next;
            B = B == nullptr ? B = headA: B->next;
        }
        return A;
    }
};*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;
        int aCount = 0, bCount = 0;
        while(A!= nullptr){
            A = A->next;
            aCount++;
        }
        while(B!= nullptr){
            B = B->next;
            bCount++;
        }

        int gap = aCount < bCount ? bCount - aCount:aCount-bCount;
        A = headA;
        B = headB;
        if(aCount < bCount){
            while(gap--) {
                B = B->next;
            }
        }
        else{
            while(gap--) {
                A = A->next;
            }
        }
        while(A != nullptr){
            if(A == B)
                return A;
            else{
                A = A->next;
                B = B->next;
            }
        }
        return nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
