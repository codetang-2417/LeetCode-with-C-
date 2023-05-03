#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/*
 * 18. 四数之和
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ret;
        int numsSize = nums.size();
        std::sort(nums.begin(), nums.end());
        int first, second;
        int left,right;
        for (first = 0; first < numsSize-3; first++) {
            if ((nums[first] > target && target>0) || (long)nums[first] + nums[first+1] +nums[first+2]+nums[first+3] > target) {//target可能是负数
                return ret;
            }
            if(first>0 && nums[first-1] == nums[first])
                continue;
            for (second = first + 1; second < numsSize; second++)
            {
                if(nums[first]+nums[second]>target){
                    return ret;
                }
                if(second > first+1 && nums[second-1] == nums[second]){
                    continue;
                }
                left = second+1;
                right = numsSize-1;
                while(left < right){
                    if(nums[left] + nums[right] > target-nums[first]-nums[second]){
                        right--;
                    }
                    else if(nums[left] + nums[right] < target-nums[first]-nums[second]){
                        left++;
                    }
                    else{
                        ret.emplace_back(vector<int>{nums[first],nums[second],nums[left],nums[right]});
                        while(left<right && nums[right-1]==nums[right]){
                            right--;
                        }
                        right--, left++;
                    }
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
