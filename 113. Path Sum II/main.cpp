#include <iostream>
#include <vector>
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
    vector <vector<int>> ret;
    void pathSum(TreeNode *root, int targetSum, vector<int> &path){
        path.push_back(root->val);
        if(targetSum == root->val && !root->left && !root->right) {//叶子结点，并且总和相等
            ret.push_back(path);
        }
        if(root->left){
            pathSum(root->left, targetSum-root->val, path);
            path.pop_back();
        }
        if(root->right){
            pathSum(root->right, targetSum-root->val, path);
            path.pop_back();
        }
    }

    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        if(!root) return ret;
        vector<int> path;
        pathSum(root,targetSum,path);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
