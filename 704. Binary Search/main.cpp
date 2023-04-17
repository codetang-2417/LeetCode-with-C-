#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid;

        while(l <= r) {
            mid = l+((r-l)>>1);
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                l = mid+1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> array = {-1,1,2,7,9,78};
    Solution slo;
    std::cout << slo.search(array,78) <<std::endl;
    return 0;
}
