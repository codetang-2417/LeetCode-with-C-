#include <iostream>
#include <array>
#include <string>

using std::string;
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::array<int,26> record{0};
        if(s.size()!=t.size()) return false;
        for(auto item : s){
            record[item-'a']++;
        }
        for(auto item : t){
            record[item-'a']--;
        }
        for(auto item : record){
            if(item!=0){
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
