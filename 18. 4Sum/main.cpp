#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;

/*
 * 18. 四数之和 与 三数之和 解法一致
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ret;
        int first, second, left, right;
        std::sort(nums.begin(),nums.end());
        for (first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            if ((long int)nums[first] + nums[first+1] + nums[first+2] + nums[first+3] > target)
                break;
            for (second = first + 1; second < nums.size(); second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                left = second + 1;
                right = nums.size()-1;
                while (left < right) {
                    if ((long int)nums[left] + nums[right] + nums[first] + nums[second] < target) {
                        left++;
                    } else if ((long int)nums[left] + nums[right] + nums[first] + nums[second] > target) {
                        right--;
                    } else {
                        ret.emplace_back(vector<int> {nums[first],nums[second],nums[left],nums[right]});
                        while (left < right && nums[right-1]==nums[right])
                            right--;
                        right--;
                        left++;
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    Solution sol;
    for (auto num: sol.fourSum(nums,0)) {
        for (auto item: num)
            std::cout << item << ", ";
        std::cout << std::endl;
    }

    return 0;
}
