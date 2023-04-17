#include <iostream>
#include <vector>

using std::vector;

/*
 * 剑指offer 59. 螺旋矩阵 II
 * leetcode 54. Spiral Matrix
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n, 0);
        int startX = 0, startY = 0;//每一次打印的起始坐标
        int loop = m < n ? m / 2 : n / 2;//取m，n中的最小值，作为loop的基准
        int offset = 0, count = 0;
        while (loop--) {
            //最上层，左闭右开
            for (; startY < n - 1 - offset; startY++) {
                res[count++] = matrix[startX][startY];
            }
            //最右侧，左闭右开
            for (; startX < m - 1 - offset; startX++) {
                res[count++] = matrix[startX][startY];
            }
            //最下层，左闭右开
            for (; startY > offset; startY--) {
                res[count++] = matrix[startX][startY];
            }
            //最左侧，左闭右开
            for (; startX > offset; startX--) {
                res[count++] = matrix[startX][startY];
            }
            startX++;startY++;
            offset++;
        }
        if(m&0x1 && m<=n){
            for(int i = 0; i<n-offset*2 ;i++)
                res[count++]=matrix[startX][startY++];
        }
        if(n&0x1 && m>n){
            for(int i = 0; i<m-offset*2 ;i++)
                res[count++]=matrix[startX++][startY];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> case1 = {{7},{9},{6}};
    auto res = sol.spiralOrder(case1);
    for (auto it: res) {
            std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}

