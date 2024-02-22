#include <iostream>
#include <stack>

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
    //不能按照层序遍历，只能根据深度遍历
    /*int getMinimumDifference(TreeNode *root) {
        std::queue<TreeNode *> que;
        que.push(root);
        int min_value = 0;
        while(!que.empty()){
            auto size = que.size();
            while(size--){
                auto cur = que.front();
                que.pop();
                if(cur->left){
                    min_value = std::min(min_value,cur->val - cur->left->val);
                    que.push(cur->left);
                }

                if(cur->right){
                    min_value = std::min(min_value,cur->right->val - cur->val);
                    que.push(cur->right);
                }
            }
        }
        return min_value;
    }*/

    //按照中序遍历，得出有序数组
    int getMinimumDifference(TreeNode *root) {
        std::stack<TreeNode *> stck;
        stck.push(root);
        TreeNode *pre;
        int ret=INT_MAX;
        while (!stck.empty()){
            auto cur = stck.top();
            stck.pop();
            if(cur){
                if(cur->right) stck.push(cur->right);
                stck.push(cur);
                stck.push(nullptr);
                if(cur->left) stck.push(cur->left);
            }
            else{
                cur = stck.top();
                stck.pop();
                if(!pre) pre = cur;
                else{
                    ret = std::min( ret, cur->val- pre->val);
                    pre = cur;
                }
            }
        }
        return ret;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
