#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* p;
    TreeNode* q;
    TreeNode * dfs(TreeNode *root){
        if(root == p || root == q || !root) return root;
        TreeNode *left = dfs(root->left);
        TreeNode *right = dfs(root->right);

        if(left&&right) return root;//返回的顺序很重要，因为已经找到公共祖先后，需要逐级返回，所以一定是先于后续判断的返回，否则就会出错
        else if(left) return left;//并且在某一个子节点找到公共组先后，需要返回
        else if(right) return right;
        else return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p, this->q = q;
        return dfs(root);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
