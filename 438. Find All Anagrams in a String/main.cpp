#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

using std::string;
using std::vector;

/*
 * 438. 找到字符串中所有字母异位词
 */

//暴力法
/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        std::array<int,26> pLetter{0};
        size_t sLen = s.size(), pLen = p.size();
        int lIndex = 0;
        if(sLen < pLen) return ret;

        for(char & ch : p)
            pLetter[ch-'a']++;
        while( lIndex <= sLen - pLen){//末尾留出一个p长度
            std::array<int,26> temp = pLetter;
            for(int i = 0; i < pLen; i++){
                temp[s[lIndex + i]-'a']--;
            }
            bool flagYes = true;
            for(int &item:temp){
                if(item<0 || item>0){
                    flagYes = false;
                    break;
                }
            }
            if(flagYes)
                ret.emplace_back(lIndex);
            lIndex++;
        }
        return ret;
    }
};*/

//滑动窗口，主要区别在于，滑动窗口不需要重复计算已经计算过得值，只需要计算每次新增的
/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int sLen = s.size(), pLen = p.size();
        if(sLen < pLen) return {};

        std::vector<int> pCount(26),sCount(26);//array不支持==等号的判断
        for(int i=0;i<pLen;i++){
            pCount[p[i] - 'a']++;//初始化p数组的字母计数，作为标准
            sCount[s[i] - 'a']++;//初始化s数组的字母计数，作为窗口
        }
        if(sCount==pCount)
            ret.emplace_back(0);
        int rIndex = pLen;
        int lIndex = 0;
        while(rIndex < sLen){
            sCount[s[lIndex]-'a']--;
            sCount[s[rIndex]-'a']++;
            if(sCount==pCount)
                ret.emplace_back(lIndex+1);
            rIndex++;
            lIndex++;
        }
        return ret;
    }
};*/
//优化滑动窗口，利用两者的差值，或者说，为了找异位词，一定是两者的字母一致，如果出现不一致的，那么前面的都可以抛弃，基于此，可以只在p的count数组上操作
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) return {};
        int lIndex=0,rIndex=0;

        std::array<int,26> count{0};
        for(char & ch : p) count[ch-'a']++;

        while(rIndex<sLen){
            if(count[s[rIndex]-'a']>0) {//右值存在于p数组中
                count[s[rIndex++]-'a']--;
            }
            else{//否则，rIndex停下来，等待lIndex到达
                count[s[lIndex++]-'a']++;
            }//当左值到达右值时，会将此值++，则if条件就满足，右值会继续下一个判断
            if(rIndex-lIndex == pLen){//如果右指针到达pLen+lIndex的位置，也就是pLen的长度，说明所有的元素都被减了，已经相等
                ret.emplace_back(lIndex);
            }
        }
        const int a = 5;
        const int *ptr = &a;
        int *ptrC = ptr;

        return ret;
    }
};

int main() {
    std::string a = "abab";
    std::string b = "ab";
    Solution sol;
    for(auto it : sol.findAnagrams(a,b)) {
        std::cout << it << std::endl;
    }
    return 0;
}
