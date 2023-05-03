#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/*
 * 15. 三数之和
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());//排序，便于去除重复，以及寻找
        int leftIndex, rightIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i - 1] == nums[i]) {//回避重复的
                continue;
            }

            rightIndex = nums.size() - 1;
            for (leftIndex = i + 1; leftIndex < rightIndex;) {

                if (leftIndex < rightIndex && (float) nums[i] + nums[leftIndex] + nums[rightIndex] > 0) {
                    rightIndex--;
                }
                else if (leftIndex < rightIndex && (float) nums[i] + nums[leftIndex] + nums[rightIndex] < 0) {
                    leftIndex++;
                }
                else if (leftIndex < rightIndex && (float) nums[i] + nums[leftIndex] + nums[rightIndex] == 0) {
                    ret.emplace_back(vector<int>{nums[i], nums[leftIndex], nums[rightIndex]});
                    while (rightIndex > i + 1 && nums[rightIndex - 1] == nums[rightIndex])
                        rightIndex--;
                    leftIndex++,rightIndex--;
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
