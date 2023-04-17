#include <iostream>

/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//常规方法
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* dummyHead = nullptr;
        ListNode* temp;
        while(head!= nullptr){//当前结点不是空
            temp = head;//将当前头结点取出
            head = head->next;//头结点后移
            temp->next = dummyHead;//将当前结点翻转
            dummyHead = temp;//移动虚拟头结点
        }
        return dummyHead;
    }
};*/


//尝试写一个递归（反向）
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;//不是递归中的步骤，而是因为如果head是nullptr,就可以直接返回
        if(head->next == nullptr) return head;//到最后一个的节点，直接返回，这是递归的最后一步
        ListNode* last = reverseList(head->next);
        head->next->next = head;//将下一个结点翻转到当前结点，覆盖了下一层的下一行赋值nullptr代码
        head->next = nullptr;//向后一个结点考虑，由于head.next赋值为nullptr后，因此这层递归返回后，会被上一层的递归，就是是上一行，覆盖，因此就是从最后一个结点，不断的向后翻转
        return last;
    }
};*/
//尝试写一个递归（正向）
class Solution {
public:

    ListNode* reverseLast(ListNode* head, ListNode* last){
        //if(head->next == nullptr)//这里不能这样判断，因为在head传入之前，head.next已经被指向倒数第二个节点了
        if(last == nullptr)
            return head;
        ListNode* temp = last->next;
        last->next = head;
        return reverseLast(last,temp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverseLast(nullptr,head);//传入参数也必须这样，因为head.next应该指向nullptr
    }
};

int main() {
    Solution sol;
    auto *head = new ListNode(0,new ListNode(1,new ListNode(2,nullptr)));
    head = sol.reverseList(head);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
