#include <iostream>
#include <vector>
#include <stack>

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
        ret.push_back(cur->val);
        Traversal(cur->right, ret);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        Traversal(root,ret);
        return ret;
    }
};*/

//迭代法
/*class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        TreeNode *cur = root;

        std::stack<TreeNode *> stackTree;
        while (!stackTree.empty() || cur != nullptr) {
            while (cur != nullptr) {
                stackTree.push(cur);
                cur = cur->left;
            }
            cur = stackTree.top();
            stackTree.pop();
            ret.emplace_back(cur->val);
            cur = cur->right;
        }
        return ret;
    }
};*/

//迭代法通用
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        std::stack<TreeNode *> stackTree;
        stackTree.push(root);
        TreeNode *cur;
        if(root == nullptr) return ret;
        while (!stackTree.empty()) {
            cur = stackTree.top();
            if (cur != nullptr) {
                stackTree.pop();
                if(cur->right != nullptr) stackTree.push(cur->right);
                stackTree.push(cur);
                stackTree.push(nullptr);
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
