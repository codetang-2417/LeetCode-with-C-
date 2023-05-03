#include <iostream>
#include <string>

using std::string;
/*
 * 459. 重复的子字符串
 */

/*//移动匹配法，就是将字符串重复拼接，再在中间寻找该字符串，如果是重复子串，就能找到对应的字符串。
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sT(s+s);
        sT.erase(sT.begin(),sT.begin()+1);
        sT.erase(sT.end()-1,sT.end());
        if(sT.find(s)!=std::string::npos)
            return true;
        else
            return false;
    }
};*/

//KMP算法，通过最大相等前后缀来找最小重复子串
class Solution {
public:
    int GetNext(string &s){
        int next[s.size()];//size函数为const返回
        int j=-1;
        next[0]=-1;
        for(int i=1;i<s.size();i++){
            while(j>=0&&s[i]!=s[j+1]){
                j=next[j];
            }
            if(s[i]==s[j+1]){
                j++;
            }
            next[i]=j;
        }
        return next[s.size()-1];
    }

    bool repeatedSubstringPattern(string s) {
        int next = GetNext(s)+1;
        int temp = s.size()-next;
        return next!=0&&s.size()%temp==0;
    }
};

int main() {
    string s("abac");
    Solution sol;
    sol.repeatedSubstringPattern(s);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
