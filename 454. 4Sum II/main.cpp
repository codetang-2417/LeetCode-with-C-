#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

/*
 * 454. 四数相加 II
 */

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int,int> sumAB;
        int count = 0;
        for(int &num1:nums1)
            for(int &num2:nums2){
                sumAB[num1+num2]++;
            }
        for(int &num3:nums3)
            for(int &num4:nums4){
                int temp = 0-num3-num4;
                if(sumAB[temp]){
                    count+=sumAB[temp];
                }
            }
        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
