#include <iostream>

#include <stack>

/*
 * 232. 用栈实现队列
 */

class MyQueue {
public:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    MyQueue() {

    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        auto returnPop = [](std::stack<int> &outputStack){
            int ret = outputStack.top();
            outputStack.pop();
            return ret;
        };
        if (!outputStack.empty()) {
            return returnPop(outputStack);
        }
        else {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
            return returnPop(outputStack);
        }
        return 0;
    }


    int peek() {
        int top = this->pop();
        outputStack.push(top);
        return top;
    }

    bool empty() {
        return (inputStack.empty()&&outputStack.empty());
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
