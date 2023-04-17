#include <iostream>
#include <vector>
#include <string>

using std::vector;

/**
 * leetcode：977. 有序数组的平方
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int lIndex = 0, rIndex = nums.size() - 1;
        vector<int> result(nums.size());
        int idRes = nums.size() - 1;
        int rNum, lNum;

        while (lIndex <= rIndex) {
            rNum = nums[rIndex] * nums[rIndex];
            lNum = nums[lIndex] * nums[lIndex];
            if (rNum < lNum) {//右指针对应的数更小
                result[idRes--] = lNum;
                lIndex++;
            } else {
                result[idRes--] = rNum;
                rIndex--;
            }
        }
        return result;
    }
};

int main() {
    vector<int> case1 = {-4, -1, 0, 3, 10};
    Solution sol;

    std::string s = "##yf#o#f";
    std::string t = "yf#o#f";
    for (auto casei: sol.sortedSquares(case1))
        std::cout << casei << std::endl;
    return 0;
}