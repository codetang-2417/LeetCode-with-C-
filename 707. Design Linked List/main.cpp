#include <iostream>
#include <vector>
#include <string>

using std::vector;

/*
 * 707. 设计链表
 */
class MyLinkedList {
public:

    MyLinkedList() {
        _size = 0;
        _dummyHead = new LinkedNode();
    }

    int get(int index) {
        int count = -1;
        LinkedNode *cur = _dummyHead;
        if (_size > index && index >0) {//有效
            while (cur != nullptr) {
                if (count == index)
                    return cur->val;
                count++;
                cur = cur->next;
            }
            return -1;
        } else
            return -1;
    }

    void addAtHead(int val) {
        _dummyHead->next = new LinkedNode(val, _dummyHead->next);
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new LinkedNode(val);
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        LinkedNode *cur = _dummyHead;
        int count = 0;//不等，count最后等于index，相等，count最后等于_size-1
        while (count != index) {
            cur = cur->next;
            count++;
        }
        auto *temp = new LinkedNode(val);
        if (cur->next != nullptr)
            temp->next = cur->next;
        cur->next = temp;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index < _size) {
            int count = 0;
            LinkedNode *cur = _dummyHead;
            while (index != count) {
                cur = cur->next;
                count++;
            }
            LinkedNode *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            _size--;
        }
    }

private:
    struct LinkedNode {
        int val;
        LinkedNode *next;

        LinkedNode() : val(0), next(nullptr) {}

        LinkedNode(int val) : val(val), next(nullptr) {}

        LinkedNode(int val, LinkedNode *node) : val(val), next(node) {}
    };

    int _size;//记录链表大小
    LinkedNode *_dummyHead;//使用虚假头
};

/**
 * Your MyLinkedList object will be instantiated and called a
 * s such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
    MyLinkedList myList;
    myList.addAtHead(1);
    myList.addAtTail(3);
    myList.addAtIndex(1,2);
    std::cout << myList.get(1)<< std::endl;
    myList.deleteAtIndex(1);
    std::cout << myList.get(1)<< std::endl;
    return 0;
}
