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

//前序遍历 递归
/*class Solution {
public:
    void Traversal(TreeNode* cur, vector<int> &ret){
        if(cur == nullptr)
            return ;
        ret.push_back(cur->val);
        Traversal(cur->left,ret);
        Traversal(cur->right,ret);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        Traversal(root, ret);
        return ret;
    }
};*/

//迭代法1：通过栈模拟
/*class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == nullptr) return ret;

        std::stack<TreeNode *> stackTree;
        TreeNode *cur;
        stackTree.push(root);
        while (!stackTree.empty()) {
            cur = stackTree.top();
            stackTree.pop();
            if (cur != nullptr)
                ret.emplace_back(cur->val);
            else
                continue;
            stackTree.push(cur->right);
            stackTree.push(cur->left);
        }
        return ret;
    }
};*/

//迭代:2：直接遍历所有左结点，因为前序遍历，中间节点和左节点是互相转换的
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        std::stack<TreeNode*> stackTree;
        TreeNode *cur = root;
        vector<int> ret;
        TreeNode *temp;
        while(!stackTree.empty() || cur != nullptr){
            while(cur!= nullptr){
                ret.emplace_back(cur->val);
                stackTree.push(cur);
                cur = cur->left;
            }
            cur = stackTree.top();
            stackTree.pop();
            cur = cur->right;//可能为空
        }
        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
