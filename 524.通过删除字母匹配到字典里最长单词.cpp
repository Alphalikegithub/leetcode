#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for(string t : dictionary){
            int i =0,j = 0;
            while(i < t.length() && j < s.length()){
                if(t[i] == s[j]){
                    ++ i;
                }
                ++ j;
            }
            if(i == t.length()){
                if(t.length() > res.length() || (t.length() == res.length() && t < res)){
                    res = t;
                }
            }
        }
        return res;
    }
};
// @lc code=end

 int main() {
    Solution solution;
    string s = "abpcplea";
    vector<string> d = {"ale", "apple", "monkey", "plea"};
    string result = solution.findLongestWord(s, d);
    std::cout << "The longest word is: " << result << std::endl;
    return 0;
}