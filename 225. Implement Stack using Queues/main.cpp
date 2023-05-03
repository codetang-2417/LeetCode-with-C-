#include <iostream>
#include <queue>

/*
 * 225. 用队列实现栈
 */
class MyStack {
public:
    std::queue<int> que,queBack;
    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;
        while(size--){
            queBack.push(que.front());
            que.pop();
        }
        int ret = que.front();
        que.pop();
        while(!queBack.empty()){
            que.push(queBack.front());
            queBack.pop();
        }
        return ret;
    }

    int top() {
        int ret = this->pop();
        this->push(ret);
        return ret;
    }

    bool empty() {
        return que.empty();
    }
};
int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_3 = obj->top();
    int param_2 = obj->pop();
    bool param_4 = obj->empty();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
