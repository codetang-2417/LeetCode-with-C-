#include <iostream>
#include <string>

using std::string;

//枚举
/*class Solution {
public:
    int countTime(string time) {
        int hh, mm;
        if (time[0] == '?') {//只有3种可能性，但要考虑time[1]的大小
            hh = time[1] < '?' ? (time[1] < '4' ? 3 : 2) : 24;
        } else {
            hh = time[1] == '?' ? (time[0] == '2' ? 4 : 10) : 1;
        }
        mm = time[3] == '?' ? 6 : 1;
        mm *= time[4] == '?' ? 10 : 1;
        return hh * mm;
    }
};*/

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
