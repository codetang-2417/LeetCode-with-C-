#include <iostream>
#include <vector>

using std::vector;

/*
 * 59. 螺旋矩阵 II
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startX = 0, startY = 0;//每一次的开始和结束位置，采用左闭右开
        int loop = n/2; //圈数，也就是循环的次数，每一次画一圈，中间的单独算
        int mid = n&0x1 ? 1:0;//奇数需要单独画中间的，偶数不需要
        int count = 1;//计数
        int offset = 0;

        while(loop--){//圈数
            //最上层，左闭右开
            for(;startY<n-1-offset;startY++){
                res[startX][startY] = count++;
            }

            //最右侧，左闭右开
            for(;startX<n-1-offset;startX++){
                res[startX][startY] = count++;
            }

            //最下层，左闭右开，从最右开始
            for(;startY>offset;startY--){
                res[startX][startY] = count++;
            }

            //最左层，从最下开始，左闭右开
            for(;startX>offset;startX--){
                res[startX][startY] = count++;
            }

            startX++;startY++;offset++;
        }
        if(mid){//单独绘制中间的点
            res[startX][startY] = count;
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.generateMatrix(3);
    for(auto it : res) {
        for (auto item: it)
            std::cout << item << " ";
        std::cout<<std::endl;
    }
    return 0;
}
