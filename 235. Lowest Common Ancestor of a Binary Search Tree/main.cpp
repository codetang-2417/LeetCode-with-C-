#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) return lowestCommonAncestor(root,q,p);
        std::queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            auto size = que.size();
            while(size--){
                auto cur = que.front();
                que.pop();
                if(cur->val>=p->val && cur->val<=q->val) return cur;
                if(cur->val > q->val){
                    que.push(cur->left);
                    continue;
                }
                if(cur->val<p->val){
                    que.push(cur->right);
                    continue;
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return nullptr;
    }*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)    return nullptr;
        if(root->val>= p->val && root->val <=q->val)    return root;
        if(root->val>= q->val && root->val <=p->val)    return root;
        if(root->val<p->val&&root->val<q->val)  return lowestCommonAncestor(root->right,p,q);
        if(root->val>p->val&&root->val>q->val)  return lowestCommonAncestor(root->left,p,q);
        return nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
