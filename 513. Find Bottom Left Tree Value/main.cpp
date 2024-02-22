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
    //层序遍历
    /*int findBottomLeftValue(TreeNode *root) {
        std::queue<TreeNode*> queTree;
        queTree.push(root);
        int ret;
        while(!queTree.empty()){
            auto size = queTree.size();
            auto cur = queTree.front();
            if(cur) ret = cur->val;
            while(size--){
                cur = queTree.front();
                queTree.pop();
                if(cur->left)   queTree.push(cur->left);
                if(cur->right)  queTree.push(cur->right);
            }
        }
        return ret;
    }*/
    //递归遍历
    //需要知道当天深度，只有最大深度的时候，左节点才有意义。因此一定要左节点优先遍历，同时还需要记录最大深度
    int max_depth=-1;
    int ret=0;

    void findDeep(TreeNode *root, int curDeep){
        if(!root->left&&!root->right) {
            if (max_depth < curDeep) {//排除同一层中非最左侧的结点，只有左节点才能被执行，后续的结点最大深度和当前深度是相同的
                max_depth=curDeep;
                ret = root->val;
            }
        }
        if(root->left){
            curDeep++;
            findDeep(root->left,curDeep);
            curDeep--;
        }
        if(root->right){
            curDeep++;
            findDeep(root->right,curDeep);
            curDeep--;
        }
    }
    int findBottomLeftValue(TreeNode *root) {
        findDeep(root,0);
        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
