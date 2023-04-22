#include <iostream>
#include <vector>
#include <string>

#include <unordered_set>
#include <algorithm>

/*
 * 202. 快乐数
 */

class Solution {
public:
    int GetHappyNext(int n){
        int ret = 0;
        int remainder;
        while(n!=0) {
            remainder = n % 10;
            ret += remainder * remainder;
            n /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        int happy=n;
        std::unordered_set<int> hashSet;

        while(happy!=1) {
            happy = GetHappyNext(happy);
            if (hashSet.count(happy) == 0)
                hashSet.insert(happy);
            else
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isHappy(2)<< std::endl;
    return 0;
}
