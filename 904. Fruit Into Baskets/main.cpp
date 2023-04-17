#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;

/**
 * leetcode：904. 水果成篮
 */

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        int beginIndex = 0, endIndex = 0;
        int result = 0;
        std::unordered_map<int,int> fruitsType;//类型为key，重复的次数为value
        while (endIndex < fruits.size()) {
            fruitsType[fruits[endIndex]]++;//每次遇到新类型，就加入，如果已经重复，就加1
            while(fruitsType.size()>2){//类型不能超过2个，如果超过了，就需要将窗口移动
                fruitsType[fruits[beginIndex]]--;//将最开始的删除，如果重复了，就减1，直到0
                if(fruitsType[fruits[beginIndex]]==0)
                    fruitsType.erase(fruits[beginIndex]);
                beginIndex++;
            }
            result = result > endIndex-beginIndex+1 ? result : endIndex-beginIndex+1;
            endIndex++;
        }
        return result;
    }
};

int main() {
    vector<int> case1 = {0,1,2,2};
    Solution sol;

    std::cout << sol.totalFruit(case1) << std::endl;
    return 0;
}