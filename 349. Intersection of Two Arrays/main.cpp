#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::vector;

/*
 * 349. 两个数组的交集
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> hashSet;
        std::unordered_set<int> result;

        for(int &num : nums1){
            hashSet.insert(num);
        }
        for(int &num:nums2){
            if(hashSet.count(num)){
                result.insert(num);
            }
        }
        return {result.begin(),result.end()};
    }
};

//用find去重结果
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        std::unordered_set<int> hashSet;
//
//        vector<int> ret;
//
//        for(int &num : nums1){
//            hashSet.insert(num);
//        }
//        for(int &num:nums2){
//            if(hashSet.count(num)){
//                if(std::find(ret.begin(), ret.end(),num)==ret.end())
//                    ret.emplace_back(num);
//            }
//        }
//        return ret;
//    }
//};

//用两个hash数组存放，有点浪费空间
//class Solution {
//public:
//
//    vector<int> GetIntersection(std::unordered_set<int> &hashSet1, std::unordered_set<int> &hashSet2){
//        if(hashSet1.size()>hashSet2.size())
//            return GetIntersection(hashSet2,hashSet1);
//        vector<int> ret;
//        for(const int &num:hashSet1){
//            if(hashSet1.count(num)&&hashSet2.count(num)){
//                ret.emplace_back(num);
//            }
//        }
//        return ret;
//    }
//
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        std::unordered_set<int> hashSet1,hashSet2;
//
//        for(int &num : nums1){
//            hashSet1.insert(num);
//        }
//        for(int &num : nums2){
//            hashSet2.insert(num);
//        }
//        return GetIntersection(hashSet1,hashSet2);
//    }
//};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
