#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归法
/*class Solution {
public:
    void Traversal(TreeNode* cur, vector<int> &ret){
        if(cur == nullptr)
            return;
        Traversal(cur->left, ret);
        Traversal(cur->right, ret);
        ret.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        Traversal(root,ret);
        return ret;
    }
};*/

//迭代法，中右左，翻转
/*class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        TreeNode *cur = root;
        std::stack<TreeNode*> stackTree;
        while(!stackTree.empty() || cur != nullptr){
            while(cur != nullptr){
                stackTree.push(cur);
                ret.emplace_back(cur->val);
                cur = cur->right;
            }
            cur = stackTree.top();
            stackTree.pop();
            cur = cur->left;
        }
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};*/

//迭代法通用
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        std::stack<TreeNode *> stackTree;
        stackTree.push(root);
        TreeNode *cur;
        if(root == nullptr) return ret;
        while (!stackTree.empty()) {
            cur = stackTree.top();
            if (cur != nullptr) {
                stackTree.pop();
                stackTree.push(cur);
                stackTree.push(nullptr);
                if(cur->right != nullptr) stackTree.push(cur->right);
                if(cur->left != nullptr) stackTree.push(cur->left);
            } else {
                stackTree.pop();
                cur = stackTree.top();
                stackTree.pop();
                ret.emplace_back(cur->val);
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
