#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        std::unordered_map<int, int> count;
        for (auto &num: nums) {
            count[num]++;//执行默认初始化
        }
        class compare {
        public:
            bool operator()(const std::pair<int,int> &parent, const std::pair<int,int> &child) {
                return parent.second > child.second;//小顶堆，当操作返回true时，执行对调，也就是当父节点大于子节点时，调换位置，所以等价于小顶堆
            }
        };
        std::priority_queue<std::pair<int,int>, vector<std::pair<int,int>>, compare> pq;


        for(auto item:count){
            pq.emplace(item);
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ret;
        while(!pq.empty()){
            ret.insert(ret.begin(),pq.top().first);
            pq.pop();
        }

    return ret;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
