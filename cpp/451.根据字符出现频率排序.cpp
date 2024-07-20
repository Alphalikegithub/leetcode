#include <string>
#include <unordered_map>
#include <algorithm>
using std::unordered_map;
using std::string;
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        // 1. 使用哈希表统计每个字符的出现频率
        unordered_map<char,int> dict; // 哈希表，键为字符，值为该字符的出现频率
        for(auto c : s){
            dict[c] ++;
        }
        // 2. 定义一个比较函数
        auto compare = [&dict](const char& a,const char& b){
            //dict[a] > dict[b]：按字符频率从高到低排序。
            //dict[a] == dict[b] && (a < b)：如果频率相同，则按字符的字典序从小到大排序。
            return (dict[a] > dict[b]  ) || (dict[a] == dict[b] && (a < b));
        };

        std::sort(s.begin(),s.end(),compare);
        return s;
    }
};
// @lc code=end

