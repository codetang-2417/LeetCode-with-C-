#include <iostream>
#include <unordered_set>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//hash
/*class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode *> hashPtrSet;
        if(headA == nullptr)
            return nullptr;
        ListNode *temp = headA;
        while(temp!= nullptr){
            hashPtrSet.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp != nullptr){
            if(hashPtrSet.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};*/

//双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *aPtr = headA, *bPtr = headB;
        while(aPtr != bPtr){
            aPtr = aPtr == nullptr ? headB: aPtr->next;
            bPtr = bPtr == nullptr ? headA: bPtr->next;
        }
        return aPtr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
