#include <iostream>
#include <vector>
#include <queue>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> ret;
        if(root == nullptr) return ret;
        std::queue<TreeNode *> queueTree;
        queueTree.push(root);
        while(!queueTree.empty()){
            auto size = queueTree.size();
            int max = queueTree.front()->val;
            while(size--){
                auto cur = queueTree.front();
                queueTree.pop();
                max = max > cur->val ? max:cur->val;
                if(cur->left!= nullptr) queueTree.push(cur->left);
                if(cur->right!= nullptr) queueTree.push(cur->right);
            }
            ret.emplace_back(max);
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
