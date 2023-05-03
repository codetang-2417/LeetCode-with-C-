#include <iostream>
#include <string>
#include <algorithm>

using std::string;

/*
 * 151. 反转字符串中的单词
 */

/*class Solution {
public:
    void removeSpace(string &s) {
        string::size_type slowIndex = 0, fastIndex = 0;

        while (fastIndex < s.size()) {
            if (s[fastIndex] != ' ') {
                if (slowIndex != 0)
                    s[slowIndex++] = ' ';
                while (fastIndex < s.size()&&s[fastIndex] != ' ') {
                    s[slowIndex++] = s[fastIndex++];
                }
            }
            fastIndex++;
        }
        s.resize(slowIndex);
    }

    string reverseWords(string s) {
        removeSpace(s);
        std::reverse(s.begin(), s.end());

        int start=0;
        for(int i=0;i<=s.size();i++){
            if( i == s.size() || s[i]==' '){
                std::reverse(s.begin()+start,s.begin()+i);
                start = i+1;
            }
        }
        return s;
    }
};*/

class Solution {
public:
    string reverseWords(string s) {
        std::reverse(s.begin(), s.end());//翻转所有字符串
        int slowIndex=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') {//跳过所有空格
                if(slowIndex!=0)//给单词首填空格
                    s[slowIndex++] = ' ';
                int start=slowIndex;
                while(i <s.size() && s[i] != ' ') s[slowIndex++] = s[i++];//把单词移到对应位置
                std::reverse(s.begin()+start,s.begin()+slowIndex);//翻转单词
            }
        }
        //s.erase(s.begin() + slowIndex,s.end());
        s.reserve(slowIndex);
        return s;
    }

};

int main() {
    Solution sol;
    sol.reverseWords(" h ty ry5   56");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
