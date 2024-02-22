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
    //假定没有重复元素；则说明要根据元素区分根节点，也就是中间结点
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(postorder.back());//后序最后一个元素是根节点
        int index;
        for(index=0;index<inorder.size();index++){
            if(inorder[index] == root->val)
                break;
        }
        std::vector<int> left_inorder(inorder.begin(),inorder.begin()+index);
        std::vector<int> right_inorder(inorder.begin()+index+1,inorder.end());
        std::vector<int> left_postorder(postorder.begin(),postorder.begin()+left_inorder.size());
        std::vector<int> right_postorder(postorder.begin()+left_inorder.size(),postorder.begin()+left_inorder.size()+right_inorder.size());

        root->left = buildTree(left_inorder,left_postorder);
        root->right = buildTree(right_inorder,right_postorder);

        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
