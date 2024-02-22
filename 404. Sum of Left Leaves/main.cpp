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
    void SumLeft(TreeNode *root, int &sum){
        if(!root) return;

        TreeNode *cur = root->left;
        if(cur){
            if(!cur->left&&!cur->right) {//都为空，说明是叶子结点
                sum += cur->val;
            }
            SumLeft(cur,sum);//相当于SumLeft(root->left,sum);
        }
        cur = root->right;
        if(cur)
            SumLeft(cur,sum);

    }

    int sumOfLeftLeaves(TreeNode *root) {
        int ret=0;
        if(!root->left&&!root->right){
            return 0;
        }
        SumLeft(root,ret);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
