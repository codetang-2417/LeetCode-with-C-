#include <iostream>
#include <vector>

using std::vector;

/**
 * leetcode：34. 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution {
public:
    int SearchBound(vector<int> &nums, int target, bool lower) {
        int res = 0;//为了防止最后一个元素为target，进不去第一个if，无法对res赋值
        int l = 0, r = nums.size()-1;
        int mid;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] < target || (lower && nums[mid] <= target)) {//左边界,右边界
                l = mid + 1;//左指针右移
                res = mid;
            } else {
                r = mid - 1;
                res = r;  //若是求右边界，则返回值是最后一次mid；若是求左边界，则返回值是mid+1，也就是r
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int  RightBound= SearchBound(nums, target, true);
        int  LeftBound= SearchBound(nums, target, false)+1;
        if(RightBound<nums.size()&&nums[RightBound] == target)
            return {LeftBound,RightBound};
        else
            return {-1,-1};
    }
};

/*强调一下，二分法应用于有序无重复数组，因为如果元素重复，返回值就不唯一*/

int main() {
    vector<int> case1 = {5,6,6,8};
    Solution sol;

    std::cout << sol.searchRange(case1, 6)[0] << " " << sol.searchRange(case1, 6)[1] << std::endl;
    return 0;
}
