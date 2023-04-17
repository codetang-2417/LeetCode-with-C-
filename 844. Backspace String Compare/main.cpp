#include <iostream>
#include <vector>
#include <string>

using std::vector;

/**
 * leetcode：844. 比较含退格的字符串
 */
/*class Solution {
public:

    int DealWithComment(std::string &s){
        int FastIndex,SlowIndex=0;
        for(FastIndex=0;FastIndex<s.size();FastIndex++){//快慢指针同时遍历两个字符串

            if(s[FastIndex]!='#'){
                s[SlowIndex++] = s[FastIndex];
            }
            else if(SlowIndex!=0){
                SlowIndex--;
            }
        }
        return SlowIndex;
    }

    bool backspaceCompare(std::string s, std::string t) {
        int sSize = DealWithComment(s);
        int tSize = DealWithComment(t);
        if(sSize!=tSize){
            return false;
        }
        else{
            for(int i=0;i<tSize;i++)
                if(t[i]!=s[i])
                    return false;
        }
        return true;
    }
};*/
class Solution {
public:

    bool backspaceCompare(std::string s, std::string t) {
        int sIndex = s.size()-1, tIndex = t.size()-1;
        int sSkip = 0, tSkip = 0;
        while(sIndex>=0 || tIndex>=0){//某一个串可能会提前结束，但另一串另需要继续判断
            while(sIndex>=0){//这是一个异步过程，会一直执行到需要比对的那一个字符串，也就是如果这个循环退出，就一定是有一个存在的字符没有比对
                if(s[sIndex] == '#'){//遇到#，退格字符加1
                    sSkip++;
                    sIndex--;
                }
                else if(sSkip>0){
                    sSkip--;
                    sIndex--;
                }
                else
                    break;
            }
            while(tIndex>=0){
                if(t[tIndex] == '#'){//遇到#，退格字符加1
                    tSkip++;
                    tIndex--;
                }
                else if(tSkip>0){//如果不是退格符，就判断是不是需要跳过
                    tSkip--;
                    tIndex--;
                }
                else
                    break;
            }
            if(sIndex>=0 && tIndex>=0){
                if(s[sIndex]!=t[tIndex]) {
                    return false;
                }//如果非退格字符不相同，说明不相等
            }
            else{//有一方达到头，此时如果由一方仍然有未比对字符，则说明不相等，就算有一方先到达头，也是在index=0时进入上一个if语句执行，而不会到这里
                if (sIndex >= 0 || tIndex >= 0) {
                    return false;
                }
            }
            tIndex--;
            sIndex--;
        }
        return true;
    }

};

int main() {
    vector<int> case1 = {1, 1, 2};
    Solution sol;

    std::string s = "##yf#o#f";
    std::string t = "yf#o#f";
    std::cout << sol.backspaceCompare(s,t)<<std::endl;
    return 0;
}
