#include <iostream>
#include <vector>
#include <string>
#include <queue>
using std::string;
using std::vector;

/*
 * 239. 滑动窗口最大值
 * 维护一个自己的队列，有如下特点：
 * 1. 拥有三个api，front；pop；push
 * 2. front总是返回当前队列中的最大值，也是窗口中的最大值
 * 3. pop将当前滑动窗口中的移出的元素，同时这个元素应该当时front元素，也就是当滑动窗口将队列中的最大值移出的时候，才pop
 * 4. push将滑动窗口中的最大值，加入到队列，队列的push会将队列排序，保证最大值在front位置
 * 由于队列是先进先出，如果要加入元素并保证元素是front，就应该将其中的小于其的部分全部pop，因此用双向队列，从后
 * 方移出元素，保证只移出小于value的元素
 * 以上保证了实现的队列是一个单调队列，按照从front开始最大往小排列。
 */

class MyQueue{
    std::deque<int> que;
public:
    int front(){
        if(!que.empty())
            return que.front();
        else
            return 0xffffffff;
    }

    void pop(const int &value){
        if(!que.empty()&&que.front()==value){
            que.pop_front();
        }
    }

    void push(const int &value){
        while(!que.empty()&&value > que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> ret;

        for(int i=0;i<k;i++)
            que.push(nums[i]);
        ret.emplace_back(que.front());
        for(int i=0;i<nums.size()-k;i++){
            que.pop(nums[i]);
            que.push(nums[i+k]);
            ret.emplace_back(que.front());
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
