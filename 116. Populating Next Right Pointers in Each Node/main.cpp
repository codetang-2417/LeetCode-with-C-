#include <iostream>
#include <queue>

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

//层序遍历，不满足常量空间要求
/*class Solution {
public:
    Node* connect(Node* root) {
        if(root== nullptr) return root;
       std::queue<Node*> queueNode;
       queueNode.push(root);
       while(!queueNode.empty()){
            auto size = queueNode.size();
           Node *cur;
            while(size--){
                cur = queueNode.front();
                queueNode.pop();
                if(!queueNode.empty()) cur->next = queueNode.front();//同一层的
                else cur->next = nullptr;
                if(cur->left) queueNode.push(cur->left);
                if(cur->right) queueNode.push(cur->right);
            }
           cur->next = nullptr;
       }
       return root;
    }
};*/

//迭代法解决
//由于是完美二叉树，每一层的叶子节点都是满的，因此分为两种情况连接
//一个结点的叶子节点，直接连接
//不同结点的叶子节点，通过结点的next连接
//class Solution {
//public:
//    Node *connect(Node *root) {
//
//        Node *cur = root;
//        Node *first;
//        if (root == nullptr) return root;
//        while (cur->left != nullptr) {//替换条件，可以加快判断速度
//            first = cur;
//            while (cur != nullptr) {
//                cur->left->next = cur->right;//一定存在
//                if (cur->next != nullptr)//next，不为空，连接不同结点之间的叶节点
//                    cur->right->next = cur->next->left;
//                cur = cur->next;
//            }
//            cur = first->left;//到开头的结点下一层
//        }
//        return root;
//    }
//};


//递归, 严格来讲这种递归不是常规的递归思想，仍然是层序遍历的；如果是深度递归，则代码会简单一些
class Solution {
public:
    void connectOnce(Node *cur, Node *first){
        if(first == nullptr) return;

        cur->left->next = cur->right;
        if(cur->next){
            cur->right->next = cur->next->left;
            connectOnce(cur->next, first);
        }else{
            connectOnce(first, first->left);
        }
        return;
    }

    Node *connect(Node *root) {
        if(root== nullptr) return nullptr;
        connectOnce(root,root->left);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
