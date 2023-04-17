#include <iostream>
#include <vector>

using std::vector;

/**
 * leetcode：26. 删除有序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int FastIndex, SlowIndex = 0;
        const int nSize = nums.size();
        for(FastIndex = 0;FastIndex < nSize; FastIndex++){
            if(nums[FastIndex]!=nums[SlowIndex]){
                nums[++SlowIndex] = nums[FastIndex];
            }
        }
        return SlowIndex+1;
    }
};

int main() {
    vector<int> case1 = {1,1,2};
    Solution sol;

    auto Csize = sol.removeDuplicates(case1);
    for(auto element : case1)
        std::cout<<element<<", ";
    std::cout << std::endl;
    for(int i = 0; i< Csize; i++)
        std::cout << case1[i] << ", ";
    return 0;
}
