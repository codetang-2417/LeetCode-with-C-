#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::vector;

/*
 * 350. 两个数组的交集 II
 */

/*class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        std::unordered_map<int, int> hashSet;
        vector<int> result;

        for(int &num : nums1){
            hashSet[num]++;
        }

        for (int &num: nums2) {
            if (hashSet.count(num)) {
                if (hashSet[num]>0)//如果值小于0，if也会判断为真，只要不为0就行
                    result.emplace_back(num);
                hashSet[num]--;
            }
        }

        return result;
    }
};*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> m;
        vector<int> res;
        for(auto i : nums1) ++m[i];
        for(auto i : nums2){
            if(m[i]){
                --m[i];
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {54, 93, 21, 73, 84, 60, 18, 62, 59, 89, 83, 89, 25, 39, 41, 55, 78, 27, 65, 82, 94, 61, 12, 38,
                         76, 5, 35, 6, 51, 48, 61, 0, 47, 60, 84, 9, 13, 28, 38, 21, 55, 37, 4, 67, 64, 86, 45, 33, 41};
    vector<int> nums2 = {17, 17, 87, 98, 18, 53, 2, 69, 74, 73, 20, 85, 59, 89, 84, 91, 84, 34, 44, 48, 20, 42, 68, 84,
                         8, 54, 66, 62, 69, 52, 67, 27, 87, 49, 92, 14, 92, 53, 22, 90, 60, 14, 8, 71, 0, 61, 94, 1, 22,
                         84, 10, 55, 55, 60, 98, 76, 27, 35, 84, 28, 4, 2, 9, 44, 86, 12, 17, 89, 35, 68, 17, 41, 21,
                         65, 59, 86, 42, 53, 0, 33, 80, 20};
    std::sort(nums1.begin(),nums1.end());
    std::sort(nums2.begin(),nums2.end());
    std::cout<<"nums1: ";
    for(auto item:nums1){
        std::cout<<item<< ", ";
    }

    std::cout << std::endl;
    std::cout<<"nums2: ";
    for(auto item:nums2){
        std::cout<<item<< ", ";
    }

    std::cout << std::endl;
    Solution sol;
    std::cout<<"re: ";
    for(auto item:sol.intersect(nums1, nums2)){
        std::cout << item << ", ";
    }
    std::cout << std::endl;
    vector<int>re{54,21,73,84,60,18,62,59,89,89,41,55,27,65,94,61,12,76,35,48,0,60,84,9,28,55,4,67,86,33};
    std::cout<<"re: ";
    std::sort(re.begin(),re.end());
    for(auto item:re){
        std::cout<<item<< ", ";
    }
    std::cout << std::endl;
    return 0;
}
