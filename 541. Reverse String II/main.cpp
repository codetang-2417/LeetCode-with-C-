#include <iostream>
#include <vector>
#include <string>

using std::string;

/*
 * 541. 反转字符串 II
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        auto reverseK = [&s](int l, int r) {
            int ll=l,rr=r-1;
            while(ll<rr){
                s[ll] ^= s[rr];
                s[rr] ^= s[ll];
                s[ll++] ^= s[rr--];
            }
        };
        int sizeS = s.size();
        int i=0;
        while(i+k < sizeS){
            reverseK(i,i+k);
            i += 2*k;
        }
        reverseK(i,sizeS);//剩余字符串不足k的情况
        return s;
    }
};

int main() {
    Solution sol;
    std::cout << sol.reverseStr("abcdefg",2) << std::endl;
    return 0;
}
