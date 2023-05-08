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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root== nullptr) return ret;
        std::queue<TreeNode*> queueTree;
        queueTree.push(root);
        while(!queueTree.empty()){
            auto size = queueTree.size();
            ret.emplace_back();
            while(size--){
                auto cur = queueTree.front();
                queueTree.pop();
                ret.back().emplace_back(cur->val);
                if(cur->left != nullptr) queueTree.push(cur->left);
                if(cur->right != nullptr) queueTree.push(cur->right);
            }
        }
        auto reverse = [&ret](){
            auto first = ret.begin(), end = ret.end()-1;
            while(first < end){
                vector<int> temp;
                temp = *end;
                *end = *first;
                *first = temp;
                first++,end--;
            }
        };
        reverse();
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
