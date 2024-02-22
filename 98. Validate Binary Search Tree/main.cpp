#include <iostream>
#include <vector>
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

    //递归算法，应当从整体考虑，因为要求右子树整体的所有节点都大于当前节点，而当前节点大于所有左子树
    //所以不能只根据当前的来看，要看左右的值；
    //因此应当依靠中序遍历，定义一个当前的最大值，并且从最左，最深的结点判断；
    //按照左中右的顺序，每一个结点都要求比最大值大，如果不是，这说明是错误的
    /*int64_t max_value = ((int64_t)1) << 63;//有符号最小值; 当测试用例中出现最小值时，则过不了，因此可以改用64位；也可以换一种方式记录
    bool isValidBST(TreeNode* root) {
        if(!root) return true;//空结点认为是true；只有返回真，才能继续判断；题目要求root至少有一个结点；
        bool left = isValidBST(root->left);
        if(root->val > max_value) max_value = root->val;
        else return false;

        bool right = isValidBST(root->right);
        return left&&right;
    }*/

    //利用中序遍历得到的顺序
    /*std::vector<int> result;
    void dfs(TreeNode* root){
        if(!root) return ;
        dfs(root->left);
        result.emplace_back(root->val);
        dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        dfs(root);
        auto it = result.begin();
        while(it!=result.end()){
            if(++it!=result.end() && *it <= *(it-1)) return false;
        }
        return true;
    }*/

    //迭代法，用通用的中序深度遍历
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        std::stack<TreeNode*> stck;
        stck.push(root);
        TreeNode * max_node = nullptr;
        while(!stck.empty()){
            auto cur = stck.top();
            stck.pop();
            if(cur){//不为空
                if(cur->right) {
                    stck.push(cur->right);
                    if(cur->right->val <= cur->val) return false;
                }
                stck.push(cur);
                stck.push(nullptr);
                if(cur->left) {
                    stck.push(cur->left);
                    if(cur->left->val >= cur->val) return false;
                }
            }
            else{
                if(!stck.empty()){
                    cur = stck.top();
                    stck.pop();
                    if(!max_node) max_node = cur;
                    else
                        if(cur->val <= max_node->val) return false;
                        else max_node = cur;
                }
            }
        }
        return true;
    }
};
int main() {
    //[32,26,47,19,null,null,56,null,27]
    TreeNode* root = new TreeNode(32, new TreeNode(26,new TreeNode(19, nullptr, new TreeNode(27)), nullptr), new TreeNode(47, nullptr,new TreeNode(56)));
    Solution sol;
    sol.isValidBST(root);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
