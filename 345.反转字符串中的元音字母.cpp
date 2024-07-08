/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <string>
#include <algorithm>
#include <unordered_set>
using std::string;
// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        std::unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0,right = s.length() - 1;
        while(left < right){
            while(left < right && vowels.find(s[left]) == vowels.end())
            {
                left ++;
            }
            while(left < right && vowels.find(s[right]) == vowels.end())
            {
                right --;
            }
            if(left < right){
                std::swap(s[left],s[right]);
                left ++ ;
                right --;
            }
        }
        return s;
    }
};
// @lc code=end

