#include <iostream>
#include <vector>

using std::vector;

/*
 * 344. 反转字符串
 */

//首尾指针翻转，swap可以用异或技巧
class Solution {
public:
    void reverseString(vector<char>& s) {
        int leftIndex=0,rightIndex=s.size()-1;
        while(leftIndex < rightIndex){
            s[leftIndex] ^= s[rightIndex];
            s[rightIndex] ^= s[leftIndex];
            s[leftIndex++] ^= s[rightIndex--];//异或交换两个值
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
