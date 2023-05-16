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

//层序遍历迭代
/*class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        std::queue<Node*> queueTree;
        queueTree.push(root);
        while(!queueTree.empty()){
            auto size = queueTree.size();
            while(size--){
                auto cur = queueTree.front();
                queueTree.pop();
                if(size > 0) cur->next = queueTree.front();//这里会将下一层的首节点包括进来，所以需要在排除最后的结点
                if(cur->left) queueTree.push(cur->left);
                if(cur->right) queueTree.push(cur->right);
            }
        }
        return root;
    }
};*/

//以链表的形式访问，遍历当层，就下层的结点链接起来，通过dummy结点保存下一层头结点。
class Solution {
public:
    Node *connect(Node *root) {
        Node *cur = root;
        Node dummy;
        Node *now = &dummy;
        while(cur!= nullptr){
            now = &dummy;
            while(cur != nullptr) {
                if (cur->left) {
                    now->next = cur->left;
                    now = now->next;
                }
                if (cur->right) {
                    now->next = cur->right;
                    now = now->next;
                }
                cur = cur->next;
            }
            cur = dummy.next;
            dummy.next = nullptr;//如果到达最低层，则dummy.next不会被更新，也就是死循环了
        }
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
