#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string,std::vector;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        std::unordered_map<std::string,std::vector<std::string>> record;
        for(auto &str : strs){
            //直接用sort，可以省略string的空间，还能加快速度
            // std::string key(26,'0');
            // for(auto &letter : str){
            //     key[letter-'a']++;
            // }
            string key=str;
            std::sort(key.begin(),key.end());
            record[key].emplace_back(std::move(str));
        }
        for(auto &item:record)
            res.emplace_back(std::move(item.second));
        return res;
    }
};

//官方的解答用到了自定义hash函数，并且用了lambda表达式，具体的含义还不清楚
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
