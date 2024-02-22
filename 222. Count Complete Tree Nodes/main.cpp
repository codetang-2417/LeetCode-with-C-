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

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *cur = root;
        int leftCnt=0, rightCnt=0;
        cur = root->left;
        while(cur){
            leftCnt++;
            cur = cur->left;
        }
        cur = root->right;
        while(cur){
            rightCnt++;
            cur = cur->right;
        }
        if(leftCnt == rightCnt) return (2 << leftCnt)-1;
        else return countNodes(root->left)+countNodes(root->right)+1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
