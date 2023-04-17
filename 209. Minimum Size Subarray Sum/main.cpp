#include <iostream>
#include <vector>
#include <string>

using std::vector;

/**
 * leetcode：209. Minimum Size Subarray Sum
 */

//暴力破解法，超时
/*class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = nums.size() + 1;
        int subSum;
        int subSize;
        for (int i = 0; i < nums.size(); i++) {
            subSum = 0;
            for (int j = i; j < nums.size(); j++) {
                subSum += nums[j];
                if (subSum >= target) {
                    subSize = j - i + 1;
                    result = subSize < result ? subSize : result;
                    break;//相当于每次的子串不断递进，从而能够找到所有满足条件的子串。
                }
            }
        }
        return result == nums.size() + 1 ? 0 : result ;
    }
};*/


//滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int subSum = 0, subSize;
        int result = 0XFFFFFFFF;
        int begin = 0;
        for (int end = 0; end < nums.size(); end++) {
            subSum += nums[end];
            while (subSum >= target){//符合要求，将进行
                subSize = end-begin+1;
                result = result > subSize ? subSize:result;
                subSum -= nums[begin++];//sum减去起始位置的数，将子串缩小
            }
        }
        return result == 0XFFFFFFFF ? 0:result;
    }
};

int main() {
    vector<int> case1 = {2, 3, 1, 2, 4, 3};
    Solution sol;

    std::cout << sol.minSubArrayLen(7, case1) << std::endl;
    return 0;
}