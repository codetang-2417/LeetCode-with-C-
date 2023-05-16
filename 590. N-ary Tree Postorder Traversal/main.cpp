#include <iostream>
#include <vector>
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

class Solution {
public:
    vector<int> postorder(Node* root) {
        std::vector<int> ret;
        std::stack<Node*> nodeStack;
        if(root == nullptr) return ret;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            auto cur = nodeStack.top();
            nodeStack.pop();
            if(cur){
                nodeStack.push(cur);
                nodeStack.push(nullptr);
                for(auto it=cur->children.rbegin();it!=cur->children.rend();it++){
                    nodeStack.push(*it);
                }
            }
            else{
                cur = nodeStack.top();
                ret.emplace_back(cur->val);
                nodeStack.pop();
            }
        }
        return ret;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
