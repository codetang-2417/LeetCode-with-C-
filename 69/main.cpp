#include <iostream>
#include <vector>

using std::vector;

/**
 * leetcode：69. x 的平方根
 */
/*class Solution {
public:
    int mySqrt(int x) {
        unsigned int bigger = x;
        unsigned int smaller=1;//这里由于最小值已经被赋值为1了，因此，不存在x/mid异常的情况；（与367题的这里对应的）
        unsigned int mid;

        while(smaller<=bigger){
            mid=smaller+((bigger-smaller)>>1);
            if(mid*mid==x)
                return mid;
            else if(mid>x/mid)
                bigger = mid-1;
            else if(mid<x/mid)
                smaller = mid+1;//确保在最后的时候还能保持前进
        }
        if(bigger*bigger<=x)
            return bigger;
        if(smaller*smaller<=x)
            return smaller;
        return -1;
    }//二分法
};*/

class Solution {
public:
    int mySqrt(int x) {
        unsigned int bigger = x;
        unsigned int smaller=1;//这里由于最小值已经被赋值为1了，因此，不存在x/mid异常的情况；（与367题的这里对应的）
        unsigned int mid;
        unsigned int res;

        while(smaller<=bigger){
            mid=smaller+((bigger-smaller)>>1);
            if(mid<=x/mid) {
                smaller = mid + 1;
                res = smaller - 1;
            }
            else
                bigger = mid - 1;
        }
        return res;
    }//二分法
};

/*强调一下，二分法应用于有序无重复数组，因为如果元素重复，返回值就不唯一*/

int main() {
    vector<int> case1 = {5,6,6,8};
    Solution sol;

    std::cout << sol.mySqrt(16) << std::endl;
    return 0;
}
