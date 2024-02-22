#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;

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
    void recursionPath(TreeNode *root, std::vector<std::string> &ret, std::string curRet) {
        if (root->left==nullptr && root->right==nullptr) {//叶子节点返回
            curRet.append("->" + std::to_string(root->val));
            ret.emplace_back(curRet);
            return;
        }
        curRet.append("->" + std::to_string(root->val));

        if(root->left)//如果不为空才继续，防止重复加入
            recursionPath(root->left, ret, curRet);
        if(root->right)
            recursionPath(root->right, ret, curRet);
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        std::vector<std::string> ret;
        recursionPath(root, ret, std::to_string(root->val));
        return ret;
    }
};


int main() {
    TreeNode *root = new TreeNode(1,new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));

    Solution sol;
    sol.binaryTreePaths(root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
