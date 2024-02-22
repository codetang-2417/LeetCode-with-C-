#include <iostream>
#include <vector>
using std::vector;
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

    //通过中序遍历
    int count=0, max_count=0;
    vector<int> ret;
    TreeNode *pre = nullptr;

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);

        //将结点的更新和count分开，否则会变得混乱
        if(!pre) count=1;
        else if(pre->val==root->val)
            count++;
        else
            count=1;
        pre = root;

        if(max_count < count){
            max_count = count;
            ret.clear();
            ret.emplace_back(pre->val);
        }
        else if(max_count == count){
            ret.emplace_back(pre->val);
        }

        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
