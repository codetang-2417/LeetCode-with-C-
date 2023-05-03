#include <iostream>
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

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head;
        if(head == nullptr) return nullptr;
        while(fastPtr!=nullptr&&fastPtr->next!= nullptr){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(slowPtr == fastPtr){
                slowPtr = head;
                while(slowPtr != fastPtr){
                    slowPtr = slowPtr->next;
                    fastPtr = fastPtr->next;
                }
                return slowPtr;
            }
        }
        return nullptr;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
