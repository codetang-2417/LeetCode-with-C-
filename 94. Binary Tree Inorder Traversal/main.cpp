#include <iostream>
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x):val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right) { }
};

class Solution {
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
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
