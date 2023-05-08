#include <iostream>
#include <vector>
#include <queue>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(const int &val) : val(val), left(nullptr), right(nullptr) {};

    TreeNode(const int &val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};

};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ret;
        if (root == nullptr) return ret;
        std::queue<TreeNode *> queueTree;
        queueTree.push(root);
        double retSum;
        while (!queueTree.empty()) {
            auto size = queueTree.size();
            retSum = 0;
            auto i = size;

            while (i--) {
                auto cur = queueTree.front();
                queueTree.pop();
                retSum += cur->val;
                if (cur->left != nullptr) queueTree.push(cur->left);
                if (cur->right != nullptr)queueTree.push(cur->right);
            }
            retSum /= size;
            ret.emplace_back(retSum);
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
