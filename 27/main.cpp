#include <iostream>
#include <vector>

using std::vector;

/**
 * leetcode：27. 移除元素
 */

/*class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int FastPtr=0,SlowPtr=0;
        for(FastPtr=0;FastPtr<nums.size();FastPtr++){
            if( val != nums[FastPtr]){
                nums[SlowPtr++] = nums[FastPtr];
            }
        }
        return  SlowPtr;//返回的是个数，不是最后一个下标值
    }
};*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int LeftIndex=0,RightIndex=nums.size()-1;
        while(LeftIndex <= RightIndex){
            while(nums[LeftIndex] != val && LeftIndex <= RightIndex){//这里需要注意，由于&&运算符号的特性，先判断第一个条件语句，如果不为真就不会判断后一个语句，因此为了防止数组溢出错误，应该将数组判断放在后边
                LeftIndex++;
            }
            while(nums[RightIndex]==val && LeftIndex <= RightIndex){
                RightIndex--;
            }
            if(LeftIndex <  RightIndex)
                nums[LeftIndex++] = nums[RightIndex--];
        }
        return  LeftIndex;//返回的是个数，不是最后一个下标值
    }
};//双向指针

int main() {
    vector<int> case1 = {1};
    Solution sol;

    std::cout << sol.removeElement(case1,1) << std::endl;
    for(auto item:case1)
        std::cout << item << ", ";
    std::cout << std::endl;
    return 0;
}
