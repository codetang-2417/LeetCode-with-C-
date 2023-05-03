#include <iostream>
#include <algorithm>

using std::string;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        auto MyReverse = [&s](const int &start,const int &end){
            int lIndex=start,rIndex=end;//左闭右开
            while(lIndex<rIndex){
                s[lIndex] ^= s[rIndex];
                s[rIndex] ^= s[lIndex];
                s[lIndex++] ^= s[rIndex--];
            }
        };
        int sSize = s.size();
        MyReverse(0,n);
        MyReverse(sSize-n,sSize);
        MyReverse(0,sSize);
        /*std::reverse(s.begin(),s.begin()+n);
        std::reverse(s.end()-n,s.end());
        std::reverse(s.begin(),s.end());*/
        return s;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
