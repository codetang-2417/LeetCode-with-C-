#include <iostream>
#include <string>

using std::string;
/*
 * 28. 找出字符串中第一个匹配项的下标
 */

class Solution {
public:
    /*void GetNextArray(string &needle, int *next){
        int j=-1,i=1;
        next[0]=j;
        for(i=1;i<needle.size();i++){
            if(needle[i] == needle[j+1]){
                next[i] = j+1;
                j++;
            }
            else{
                while(j>=0&&needle[j+1]!=needle[i]){
                    j = next[j];
                }
                if(needle[i] == needle[j+1]){
                    j++;
                }
                next[i]=j;
            }
        }
    }*/

    void GetNextArray(string &needle, int *next){
        int j=-1,i=1;
        next[0]=j;
        for(i=1;i<needle.size();i++){
            while (j >= 0 && needle[j + 1] != needle[i]) {
                j = next[j];
            }
            if (needle[i] == needle[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }

    //j表示当前模式串字符
    int strStr(string haystack, string needle) {
        int *next = new int[needle.size()];
        GetNextArray(needle, next);
        int i,j=0;
        for(i=0;i<haystack.size();i++){
            while(j>0&&needle[j]!=haystack[i]){
                j = next[j-1]+1;
            }
            if(needle[j]==haystack[i]){
                j++;
            }
            if(j==needle.size()){
                return i-j+1;
            }
        }
        return -1;
    }
    //j表示前一个模式串字符
    int strStr(string haystack, string needle) {
        int *next = new int[needle.size()];
        GetNextArray(needle, next);
        int j=-1;
        for(int i=0;i<haystack.size();i++){
            while(j>=0&&needle[j+1]!=haystack[i]){//j>=0是因为，最终j会=-1，因为next[0]=-1，找不到匹配的情况下，最终会回溯到next[0]
                j=next[j];//j始终是指向的前一个字符，next[j]也是
            }
            if(needle[j+1]==haystack[i]){
                j++;
            }
            if(j == needle.size()-1){//j-1已经判断了
                return i-j;//不需要加1
            }
        }
    }
};

int main() {
    string haystack("aabaaabaaac");
    string needle("aabaaac");
    Solution sol;


    std::cout << sol.strStr(haystack,needle)<< std::endl;
    return 0;
}
