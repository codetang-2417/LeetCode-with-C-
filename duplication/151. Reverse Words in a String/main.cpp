#include <iostream>
#include <string>

using std::string;


class Solution {
public:
    string reverseWords(string s) {
        auto ReverseOnce = [&s](int left, int right) {
            while (left < right) {
                s[left] ^= s[right];
                s[right] ^= s[left];
                s[left++] ^= s[right--];
            }
        };
        int sSize = s.size();
        int begin;
        ReverseOnce(0, sSize - 1);
        int slow = 0, fast = 0;
        while (fast < s.size()){
            if(s[fast] != ' '){
                begin = slow;
                while(fast < sSize && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
                ReverseOnce(begin,slow-1);
                if(slow!=0)//给单词首填空格
                    s[slow++] = ' ';
            }
            fast++;
        }
        s.resize(slow);
        return s;
    }
};

int main() {

    Solution sol;
    sol.reverseWords("the sky is blue");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
