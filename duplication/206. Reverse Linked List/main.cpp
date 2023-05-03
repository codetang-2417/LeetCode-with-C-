#include <iostream>

/*
 * 206. 反转链表
 */

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

//从开头递归返回
/*class Solution {
public:
    ListNode * reverseListOnce(ListNode *now, ListNode *remain){
        if(remain == nullptr){
            return now;
        }
        ListNode * last = remain->next;
        remain->next = now;

        return reverseListOnce(remain, last);
    }
    ListNode *reverseList(ListNode *head) {
        return reverseListOnce(nullptr, head);
    }
};*/


//从末尾递归返回
/*class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return ret;
    }
};*/

//双指针
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode temp(0,head);
        ListNode *dummyHead = &temp;
        ListNode *now = head, *last = nullptr;
        ListNode *remain;
        while(now != nullptr){
            remain = now->next;//保留剩余的结点
            now->next = last;//当前结点指向上一结点
            last = now;//上一节点移动到当前结点
            now = remain;//当前结点移动到下一结点
        }
        return last;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
