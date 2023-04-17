#include <iostream>
#include <vector>

using std::vector;

/**
 * leetcode：283. 移动零
 */
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int FastIndex, SlowIndex = 0;
        for(FastIndex = 0; FastIndex < nums.size(); FastIndex++){
            if(nums[FastIndex] != 0){
                nums[SlowIndex++] = nums[FastIndex];
            }
        }
        while(SlowIndex<nums.size()){
            nums[SlowIndex++] = 0;
        }
    }
};

int main() {
    vector<int> case1 = {0,1,0,3,12};
    Solution sol;
    sol.moveZeroes(case1);
    for(auto Element : case1)
        std::cout << Element << std::endl;
    return 0;
}
