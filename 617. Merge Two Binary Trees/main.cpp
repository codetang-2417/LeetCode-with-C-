#include <iostream>
#include <queue>

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
    /*//重复利用其中一个树，作为返回的树
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;//这里直接将有值的树整个返回，拼接到结果上，所以后续的所有树都不用遍历，而直接被放到了结果的树上。
        if(!root2) return root1;
        root1->val+=root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;
    }*/
    //新建树，作为返回的树
    /*TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;//这里直接将有值的树整个返回，拼接到结果上，所以后续的所有树都不用遍历，而直接被放到了结果的树上。
        if(!root2) return root1;
        TreeNode *root= new TreeNode(root1->val+root2->val);

        root->left = mergeTrees(root1->left,root2->left);
        root->right = mergeTrees(root1->right,root2->right);
        return root;
    }*/

    //迭代法
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        TreeNode* root = new TreeNode();
        TreeNode* cur_root;
        std::queue<TreeNode *> que;
        que.push(root1);
        que.push(root2);
        que.push(root);
        while(!que.empty()){
            auto cur1 = que.front();
            que.pop();
            auto cur2 = que.front();
            que.pop();
            cur_root = que.front();
            que.pop();
            cur_root->val=cur1->val + cur2->val;
            if(cur1->left&&cur2->left){
                que.push(cur1->left);
                que.push(cur2->left);
                cur_root->left = new TreeNode();
                que.push(cur_root->left);
            }
            if(cur1->right&&cur2->right){
                que.push(cur1->right);
                que.push(cur2->right);
                cur_root->right = new TreeNode();
                que.push(cur_root->right);
            }
            if(!cur1->left&&cur2->left)
                cur_root->left = cur2->left;
            else if(cur1->left&&!cur2->left)
                cur_root->left = cur1->left;

            if(!cur1->right&&cur2->right)
                cur_root->right = cur2->right;
            else if(cur1->right&&!cur2->right)
                cur_root->right = cur1->right;

        }
        return root;

    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
