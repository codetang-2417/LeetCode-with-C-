#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if(root == nullptr) return nullptr;

        std::swap(root->left,root->right);

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};*/

//前序遍历
class Solution {
private:
    int ret=1;
public:

    TreeNode *invertTree(TreeNode *root) {
        if(root== nullptr) return nullptr;
        std::stack<TreeNode*> stackTree;
        stackTree.push(root);
        while(!stackTree.empty()){
            auto cur = stackTree.top();
            stackTree.pop();
            if(cur != nullptr){
                if(cur->right) stackTree.push(cur->right);
                if(cur->left) stackTree.push(cur->left);
                stackTree.push(cur);
                stackTree.push(nullptr);
            }
            else {
                cur = stackTree.top();
                stackTree.pop();
                std::swap(cur->left,cur->right);
            }
        }
        return root;
    }
};



int main() {


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
