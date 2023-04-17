#include <iostream>
#include <vector>
#include <string>

using std::vector;

/**
 * 203. 移除链表元素
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyNode = new ListNode(0, head);//链表定义必须是指针，且在堆上分配空间，在栈上分配不能够持久
        ListNode *cur = dummyNode;
        while (cur->next != nullptr) {
            if (cur->next->val == val){
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else{
                cur = cur->next;
            }
        }
        //还需要考虑new出的虚拟结点的释放
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
