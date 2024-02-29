#include <iostream>
/**
 * leetcode：367. 有效的完全平方数
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        long int l=1,r=num,m,ret;// 防止溢出
        while(l<=r){
            m=l+(r-l)/2;
            if(num-m*m==0)
                return true;
            if(num-m*m>0)
                l = m+1;
            else
                r = m -1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    std::cout << sol.isPerfectSquare(16) << std::endl;
    return 0;
}
