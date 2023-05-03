#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    string replaceSpace(string s) {
        int sSize = s.size();
        int sizeSpace=sSize;
        for(char &ch:s){
            if(ch == ' ')
                sizeSpace+=2;
        }
        string newString(sizeSpace,' ');
        int slowIndex=0,fastIndex=0;
        while(fastIndex<sSize){
            /*while(fastIndex<sSize && s[fastIndex]!=' '){
                newString[slowIndex++]=s[fastIndex++];
            }
            if(slowIndex<sizeSpace){
                newString[slowIndex++] = '%';
                newString[slowIndex++] = '2';
                newString[slowIndex++] = '0';
                fastIndex++;
            }*/
            if(s[fastIndex]!=' '){
                newString[slowIndex++]=s[fastIndex++];
            }
            else{
                newString[slowIndex++] = '%';
                newString[slowIndex++] = '2';
                newString[slowIndex++] = '0';
                fastIndex++;
            }


        }
        return newString;
    }
};



int main() {
    Solution sol;
    sol.replaceSpace("We are happy.");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
