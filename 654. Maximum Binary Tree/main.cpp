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
    /*TreeNode *construct(vector<int> &nums, int left, int right){
        if(left >= right) return nullptr;
        int maxId = left;
        for(int i=left; i<right;i++){
            if(nums[maxId] < nums[i]) {
                maxId = i;
            }
        }
        TreeNode *root = new TreeNode(nums[maxId],construct(nums, left, maxId),construct(nums, maxId+1, right));
        return root;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return construct(nums,0,nums.size());
    }*/


    TreeNode *construct(vector<int> &nums, int left, int right){
        if(left == right){
            return nullptr;
        }

        int index;
        int max = nums[left], max_index;
        for(index=left;index<right;index++){
            if(max < nums[index]) {
                max = nums[index];
                max_index = index;
            }
        }
        TreeNode *root = new TreeNode(nums[max_index]);
        root->left = construct(nums, left, max_index);
        root->right = construct(nums, max_index+1, right);
        return root;

    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return construct(nums, 0, nums.size());
    }
};

int main() {
    char a[10] = "hello";
    char *ptr=a;
    printf("%c\n",++*ptr);
    printf("%c\n",*ptr++);
    printf("%c\n",(*ptr)++);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
