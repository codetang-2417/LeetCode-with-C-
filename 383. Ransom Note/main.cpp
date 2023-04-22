#include <iostream>
#include <array>
#include <string>

using std::string;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::array<int,26> record{0};
        if(magazine.size() < ransomNote.size()) return false;
        for(auto item : magazine){//统计杂志中每个字符数量
            record[item-'a']++;
        }
        for(auto item : ransomNote){
            record[item-'a']--;
        }
        for(auto item : record){
            if(item<0){
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
