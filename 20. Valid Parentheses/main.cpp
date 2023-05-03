#include <iostream>
#include <string>
#include <stack>

/*
 * 20. 有效的括号
 */

using std::string;
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stackBrackets;
        int sizeS = s.size();

        for(int i=0;i<sizeS;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                stackBrackets.push(s[i]);
            else{
                if(stackBrackets.empty())
                    return false;
                switch(s[i]){
                    case ')':
                        if(stackBrackets.top() != '(')
                            return false;
                        break;
                    case ']':
                        if(stackBrackets.top() != '[')
                            return false;
                        break;
                    case '}':
                        if(stackBrackets.top() != '{')
                            return false;
                        break;
                    default:return false;
                }
                stackBrackets.pop();
            }
        }
        if(stackBrackets.empty())
            return true;
        else
            return false;
    }
};

int main() {
    Solution sol;
    sol.isValid("]");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
