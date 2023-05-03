#include <iostream>
#include <string>
using std::string;

/*
 * 剑指 Offer 05. 替换空格
 */

class Solution {
public:
    string replaceSpace(string s) {
        int oldSize = s.size();
        int newSize = oldSize;
        for(char &ch:s){
            if(ch==' '){
                newSize+=2;
            }
        }
        s.resize(newSize);
        int lIndex=oldSize-1,rIndex=newSize-1;

        while(lIndex>0){
            if(s[lIndex] == ' '){
                s[rIndex--]='0';
                s[rIndex--]='2';
                s[rIndex--]='%';
                lIndex--;
            }
            else{
                s[rIndex--] = s[lIndex--];
            }
        }

        return s;
    }
};

int main() {
    std::cout << "H,ello World!" << std::endl;
    return 0;
}
