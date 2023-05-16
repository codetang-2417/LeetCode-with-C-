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

    int minDepth(TreeNode *root) {
        if(root== nullptr) return 0;
        std::queue<TreeNode*> queueTree;
        queueTree.push(root);
        int depth=1;
        int ret = -1;

        while(!queueTree.empty()){//不为空，则有结点还没遍历完
            auto size = queueTree.size();
            while(size--){
                auto cur = queueTree.front();
                queueTree.pop();
                if(cur->left== nullptr && cur->right== nullptr){//叶子节点。
                    ret = ret==-1?depth:std::min(ret,depth);//没有必要，因为如果从上往下遍历，则一定是最小深度
                }
                if(cur->left) queueTree.push(cur->left);
                if(cur->right) queueTree.push(cur->right);
            }
            depth++;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
