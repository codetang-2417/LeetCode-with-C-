#include <iostream>
#include <vector>
#include <queue>
using std::vector;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;
        std::queue<TreeNode*> queueTree;
        queueTree.push(root);
        while(!queueTree.empty()){
            auto size = queueTree.size();

            ret.emplace_back(queueTree.front()->val);//遇到的第一个肯定是从右看到的第一个结点，因为下面程层序遍历也是从最右开始的
            while(size--){
                auto cur = queueTree.front();
                queueTree.pop();
                if(cur->right!= nullptr) queueTree.push(cur->right);
                if(cur->left!= nullptr) queueTree.push(cur->left);
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
