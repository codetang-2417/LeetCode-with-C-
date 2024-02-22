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

    //递归法
    /*bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(!p||!q) return false;
        if(p->val!=q->val) return false;
        return  isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }*/

    //迭代法
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode *> queueTree;
        queueTree.push(p),queueTree.push(q);
        while(!queueTree.empty()){
            auto pNode = queueTree.front();
            queueTree.pop();
            auto qNode = queueTree.front();
            queueTree.pop();
            if(!pNode&&!qNode){//两者为空
                continue;
            }
            if(!pNode||!qNode){//其中之一为空
                return false;
            }
            else{
                if(pNode->val!=qNode->val){
                    return false;
                }
                queueTree.push(p->left);
                queueTree.push(q->left);
                queueTree.push(p->right);
                queueTree.push(q->right);
            }
        }
        return true;
    }
};

int main() {
    TreeNode p(1,new TreeNode(2), new TreeNode(3));
    TreeNode q(1,new TreeNode(2), new TreeNode(3));
    Solution sol;
    sol.isSameTree(&p,&q);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
