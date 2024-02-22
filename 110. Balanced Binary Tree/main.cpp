#include <iostream>


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

    int get_height(TreeNode *root){
        if(!root) return 0;
        int left = get_height(root->left);
        if(left==-1) return -1;
        int right = get_height(root->right);
        if(right==-1) return -1;
        int diff = left>right?left - right:right-left;
        if(diff > 1) return -1;
        else return left > right?left+1:right+1;
    }

    bool isBalanced(TreeNode *root) {
        return get_height(root)<0?false:true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
