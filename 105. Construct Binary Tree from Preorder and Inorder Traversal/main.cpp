#include <iostream>
#include <vector>
#include <unordered_map>

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
    /*TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty())    return nullptr;//由于前序遍历完左子树，剩下的是右子树，但是如果只判断前序数组为空返回，那么当中序为空时，就无法判断了，这也是为什么一定要两个序列，才能生成一棵树；
        TreeNode *root = new TreeNode(preorder.front());

        int index=0;
        for(index=0;index<inorder.size();index++){
            if(inorder[index]==root->val) break;
        }
        vector<int> left_tree(inorder.begin(),inorder.begin()+index);
        vector<int> right_tree(inorder.begin()+index+1,inorder.end());
        preorder.erase(preorder.begin());
        root->left = buildTree(preorder,left_tree);
        root->right = buildTree(preorder,right_tree);

        return root;
    }*/
    std::unordered_map <int ,int > u_map;
    TreeNode *buildTree(vector<int> &preorder, int left_pre, int right_pre, vector<int> &inorder, int left_in, int right_in) {
        if (preorder.empty()) return nullptr;
        if (left_pre == right_pre) return nullptr;
        TreeNode *root = new TreeNode(preorder[left_pre]);
        int index;
        index = u_map[root->val];//用哈希数组，大大加快查找速度
        /*for (index = left_in; index < right_in; index++) {
            if (inorder[index] == root->val) break;
        }*/
        root->left = buildTree(preorder, left_pre + 1, left_pre + 1 + index - left_in, inorder, left_in, index);
        root->right = buildTree(preorder, left_pre + 1 + index - left_in, right_pre, inorder, index + 1, right_in);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for(int i=0;i<inorder.size();i++) u_map[inorder[i]]=i;
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
