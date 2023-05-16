#include <iostream>
#include <string>
#include <array>

using std::string;

/*
 * 28. 找出字符串中第一个匹配项的下标
 */

/*class Solution {
public:
    void GenNext(const string &needle, int next[]) {
        int j = -1, i = 1;
        next[0] = j;
        auto size = needle.size();
        while(i<size){
            if(j>=0 && needle[j+1] != needle[i]){
                j = next[j];
            }
            if(needle[j+1]==needle[i]){
                j++;
            }
            next[i]=j;
            i++;
        }
    }

    int strStr(string haystack, string needle) {
        const int size = needle.size();
        int *next = new int[size];
        GenNext(needle, next);
        int j=-1,i=0;
        auto bug0 = haystack.substr(84,8);
        auto bug = haystack.substr(92,11);
        while(i<haystack.size()){
            while(j>=0&& haystack[i]!=needle[j+1]){//与next数组不同的点，需要一直返回到首位，也就是不匹配就一直返回，而不是值返回一次
                j = next[j];
            }
            if(j+1 < size && haystack[i]==needle[j+1]){
                j++;
            }
            if(j == size-1) return i-size+1;
            i++;
        }
        return -1;
    }
};*/

/*class Solution {
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
/*

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
                delete []next;
                return i-j;//不需要加1
            }
        }
        return -1;
    }
};*/
class Solution {
public:
    void GenNext(const string &needle, int next[]){
        int j=0,i=1;//定义j为前缀的最后一个字符，i定义为后缀的最后一个字符
        next[0] = j;
        for(;i<needle.size();i++){
            if(j>0 && needle[i]!=needle[j]) {//仍然需要在前，
                j = next[j-1];
            }
            if(needle[i] == needle[j]) {//前缀最后一个字符，后缀最后一个字符相等
                j++;
            }
            next[i]=j;//这里回退的地址也变成了，相等前缀+1；
        }
    }
    int strStr(string haystack, string needle) {
        int *next = new int[needle.size()];
        GenNext(needle,next);
        int j=0,i=0;//定义j为相等前后缀后一字符，或者是当前字符
        for(;i<haystack.size();i++){
            while(j > 0 && haystack[i]!=needle[j]){
                j = next[j-1];
            }
            if(haystack[i]==needle[j]){
                j++;
            }
            if(j==needle.size()){
                delete[] next;
                return i-j+1;
            }
        }
        delete[] next;
        return -1;
    }
};



int main() {
    string haystack("ababaabbbbababbaabaaabaabbaaaabbabaabbbbbbabbaabbabbbabbbbbaaabaababbbaabbbabbbaabbbbaaabbababbabbbabaaabbaabbabababbbaaaaaaababbabaababaabbbbaaabbbabb");
    string needle("abbabbbabaa");
    Solution sol;


    std::cout << sol.strStr(haystack, needle) << std::endl;
    return 0;
}
