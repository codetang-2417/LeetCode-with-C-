#include <iostream>
#include <queue>

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
    /*//递归写法
    bool check(TreeNode *left, TreeNode *right){
        if(left== nullptr && right == nullptr) return true;
        if(left== nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;
        return check(left->left,right->right) && check(left->right,right->left);
    }
    bool isSymmetric(TreeNode *root) {
        return check(root->left,root->right);
    }*/

    //迭代写法
    bool isSymmetric(TreeNode *root) {
        std::queue<TreeNode*> treeQ;
        if(root== nullptr)  return false;
        treeQ.push(root->left);
        treeQ.push(root->right);
        while(!treeQ.empty()){
            auto left = treeQ.front();
            treeQ.pop();
            auto right = treeQ.front();
            treeQ.pop();
            if(!left&&!right) {//都为空
                continue;
            }
            if(!left||!right){//其中一个为空
                return false;
            }
            //则后续的都不为空了
            if(left->val!=right->val) return false;
            treeQ.push(left->left);
            treeQ.push(right->right);
            treeQ.push(left->right);
            treeQ.push(right->left);
        }
        return true;
    }
};



int main() {

    TreeNode root(1,new TreeNode(2, nullptr,new TreeNode(3)),new TreeNode(2, new TreeNode(3),nullptr));
    Solution sol;
    sol.isSymmetric(&root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
