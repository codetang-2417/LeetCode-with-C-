#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    void reverseString(vector<char> &s) {
        int leftIndex = 0, rightIndex = s.size() - 1;
        while(leftIndex<rightIndex){
            s[leftIndex] ^= s[rightIndex];
            s[rightIndex] ^= s[leftIndex];
            s[leftIndex++] ^= s[rightIndex--];
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
