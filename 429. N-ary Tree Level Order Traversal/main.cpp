#include <iostream>
#include <vector>
#include <queue>

using std::vector;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;

        std::queue<Node *> queueNode;
        queueNode.push(root);
        while (!queueNode.empty()) {
            auto size = queueNode.size();//当前这层的size
            ret.emplace_back();
            while (size--) {
                auto cur = queueNode.front();
                queueNode.pop();
                ret.back().emplace_back(cur->val);
                if(!cur->children.empty())
                    for (auto item: cur->children)
                        queueNode.push(item);
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
