#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hashMap;
        int targetAnother;
        for(int i=0;i<nums.size();i++){
            targetAnother = target-nums[i];
            if(hashMap.count(targetAnother)){
                return {i,hashMap[targetAnother]};
            }
            else{
                hashMap[nums[i]] = i;
            }
        }
        return {};
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
