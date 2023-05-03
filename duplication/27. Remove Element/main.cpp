#include <iostream>
#include <vector>

using std::vector;
/*
 * 27. 移除元素
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lIndex = 0, rIndex = nums.size()-1;

        while(lIndex <= rIndex){
            while(lIndex <= rIndex && nums[lIndex]!=val){
                lIndex++;
            }
            while(lIndex <= rIndex && nums[rIndex]==val){
                rIndex--;
            }
            if(lIndex<rIndex)
                nums[lIndex] = nums[rIndex];
        }
        return lIndex;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
