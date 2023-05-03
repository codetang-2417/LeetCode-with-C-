#include <iostream>
#include <stack>
#include <string>
using std::string;
/*
 * 1047. 删除字符串中的所有相邻重复项
 */

class Solution {
public:
    string removeDuplicates(string s) {
        string ret;
        for(auto ch : s){
            if(ret.empty() || ret.back() != ch){//如果为空，或者栈顶与当前字符不同，就压栈
                ret.push_back(ch);
            }
            else{//相同
                ret.pop_back();
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
