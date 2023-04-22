#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;

/*
 * 15. 三数之和
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());//排序很关键
        int first, left, right;
        for (first = 0; first < nums.size(); first++) {
            if (nums[first] > 0) {
                return ret;
            }
            if (first > 0 && nums[first - 1] == nums[first]) {//防止与上一次判断过的值重复
                continue;//通过这种写法，能够减少后续代码的缩进量
            }

            left = first + 1;
            right =(int) (nums.size()-1);

            while (left < right) {

                if (nums[right] + nums[first] + nums[left] > 0) {
                    right--;
                }
                else if(nums[right] + nums[first] + nums[left] < 0){
                    left++;
                }
                else{
                    ret.emplace_back(vector<int>{nums[first],nums[left],nums[right]});
                    while(left < right &&nums[right-1]==nums[right]){//容易导致right溢出，-1的时候访问非法
                        right--;
                    }
                    right--;
                    left++;
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {-1,0,1,0};
    Solution sol;
    for(auto num:sol.threeSum(nums)){
        for(auto item:num)
            std::cout << item << ", " ;
        std::cout << std::endl;
    }

    return 0;
}
