#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
    /*int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        for(auto item : root->children){
            depth=std::max(maxDepth(item),depth);
        }
        return depth+1;
    }*/
    int maxDepth(Node* root) {
        int ret=0;
        if(root == nullptr) return 0;
        std::queue<Node*> nodeQ;
        nodeQ.push(root);
        while(!nodeQ.empty()){
            auto size = nodeQ.size();
            while(size--) {
                auto cur = nodeQ.front();
                nodeQ.pop();
                for (auto item: cur->children) {
                    nodeQ.push(item);
                }
            }
            ret++;//层数加1
        }
        return ret+1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
