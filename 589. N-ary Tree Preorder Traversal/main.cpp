#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


//class Solution {
//public:
//    //使用层序遍历
//    vector<int> preorder(Node* root) {
//        std::vector<int> ret;
//        if(root== nullptr) return ret;
//        std::queue<Node*> nodeQ;
//        nodeQ.push(root);
//        while(!nodeQ.empty()){
//            auto size = nodeQ.size();
//            while(size--){
//                auto cur = nodeQ.front();
//                nodeQ.pop();
//                ret.emplace_back(cur->val);
//                for(auto item : cur->children){
//                    if(item) nodeQ.push(item);
//                }
//            }
//        }
//        return ret;
//    }
//};


class Solution {
public:
    /*//使用递归深度遍历
    void perorderOnce(Node *root,std::vector<int> &ret){
        if(root == nullptr) return;
        ret.emplace_back(root->val);
        for(auto item:root->children)//递归遍历每一层，但不是层序遍历，因为每一次都进入到子节点的第一个，子节点遍历完后，才遍历下一个子节点
            perorderOnce(item,ret);
    }

    vector<int> preorder(Node *root) {
        std::vector<int> ret;
        perorderOnce(root,ret);
        return ret;
    }*/
    //迭代法，通用模板，标记法，前序遍历
    vector<int> preorder(Node *root) {
        std::vector<int> ret;
        if(root == nullptr)  return ret;
        std::stack<Node*> nodeStack;
        nodeStack.push(root);

        while(!nodeStack.empty()){
            auto cur = nodeStack.top();
            nodeStack.pop();
            if(cur!= nullptr) {
                for (auto it = cur->children.rbegin(); it != cur->children.rend(); it++) {//迭代器的使用
                    nodeStack.push(*it);
                }
                nodeStack.push(cur);
                nodeStack.push(nullptr);
            }
            else{
                cur = nodeStack.top();//获得元素
                ret.emplace_back(cur->val);
                nodeStack.pop();//弹出元素
            }
        }
        return ret;
    }
};


int main() {
    Node child_0(3),child_1(2),child_2(4);
    vector<Node*> children{&child_0,&child_1,&child_2};
    Node root(1,children);
    Solution sol;
    sol.preorder(&root);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
