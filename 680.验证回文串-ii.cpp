/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */
#include <string>
#include <iostream>
using std::string;
// @lc code=start
class Solution {
public:
    //辅助函数，检查字符串s是否为回文串
    bool isPalindrome(const string& s,int left ,int right)
    {
        while(left < right){
            if(s[left] != s[right]){
                return false;//如果遇到不相等的字符串，则不是回文串
            }
            left++;
            right --;
        }
        return true;//如果通过整个检查过程，则是字符串
    }
    //主函数，检查字符串s是否可以通过删除最多一个字符成为回文串
    bool validPalindrome(string s) {
        /* 回文字符串：是一个正读和反读都一样的字符串 */
        int left = 0;
        int right = s.length() -1;
        /* 在 C++ 标准库的 std::string 类中，s.length() 和 s.size() 是完全等价的。
        它们都返回字符串的长度（字符数）。
        两者的实现和性能是相同的，调用其中一个就等于调用另一个。 */
        while(left < right){
            if(s[left] == s[right]){
                ++left;
                --right;
            }else{
                //如果遇到不相等的字符串，尝试跳过左字符或右字符后再检查是否为回文串
                return isPalindrome(s,left + 1,right) || isPalindrome(s,left,right -1);
            }
        }
        
        return true;
    }
};
// @lc code=end

