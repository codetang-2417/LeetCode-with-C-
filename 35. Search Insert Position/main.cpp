#include <iostream>
#include <vector>

using std::vector;
/**
 * leetcode：35. 搜索插入位置
 */
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid - 1;
        }
        return l;//根据题目要求，输出的插入位置，是大于target的右下标（因为是从1开始计数的，所以如果小于所有元素，返回0，大于所有元素，返回数组大小），而循环停止条件是l > r，所以l才是符合要求的返回值
    }
};

/*强调一下，二分法应用于有序无重复数组，因为如果元素重复，返回值就不唯一*/

int main() {
    vector<int> case1 = {1, 3, 5, 6};
    Solution sol;

    std::cout << sol.searchInsert(case1,-1) << std::endl;
    return 0;
}
