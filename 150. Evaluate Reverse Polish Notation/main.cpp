#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::string;
using std::vector;

/*
 * 150. 逆波兰表达式求值
 */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::stack<int> ret;
        int op1,op2;
        auto GetOp = [&ret,&op1,&op2](){
            op2 = ret.top();
            ret.pop();
            op1 = ret.top();
            ret.pop();
        };
        for (string cur: tokens) {
            if (cur == "+") {
                GetOp();
                ret.push(op1 + op2);
            } else if (cur == "-") {
                GetOp();
                ret.push(op1 - op2);
            } else if (cur == "*") {
                GetOp();
                ret.push(op1 * op2);
            }else if (cur == "/") {
                GetOp();
                ret.push(op1 / op2);
            }
            else{//操作数
                ret.push(std::stoi(cur));
            }
            return ret.top();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
