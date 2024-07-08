/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include <math.h>
// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        //要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 
        //b = 0 也满足条件，即a^2 + 0 = c
        /* 
        在计算的过程中可能会发生 int 型溢出的情况，
        需要使用 long 型避免溢出。
         */
        long left = 0;
        long right = (int)sqrt(c);//取整
        while(left <= right){
            long sum = left * left + right * right;
            if(sum == c)
            {
                return true;
            }else if(sum > c){
                right --;
            }else{
                left ++;
            }
        }
        return false;
    }
};
// @lc code=end

 