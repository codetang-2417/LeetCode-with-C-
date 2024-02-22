#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//给定的是二叉搜索树BST，需要用到二叉搜索树的性质，可以加快搜索速度
class Solution {
public:
    /*TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr || root->val == val) return root;
        TreeNode *ret;
        if(root->val > val) ret = searchBST(root->left, val);
        if (ret)
            return ret;
        if(root->val < val) ret = searchBST(root->right, val);
        if(ret)
            return ret;
        return nullptr;
    }*/

    //迭代法
    TreeNode *searchBST(TreeNode *root, int val) {
        while(root){
            if(root->val == val) return root;
            else if(root->val > val) root = root->left;
            else if(root->val < val) root = root->right;
        }
        return root;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
