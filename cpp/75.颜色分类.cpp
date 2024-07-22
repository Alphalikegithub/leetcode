#include <vector>
using std::vector;
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for(int i = 0;i <= right;i++){
            if(nums[i] == 0){
                swap(nums,i,left);
                left ++;
            }else if(nums[i] == 2){
                swap(nums,i,right);
                right --;
                if(nums[i] != 1){
                    i --;
                }
            }
        }
    }
    void swap(vector<int>& nums,int index1,int index2){
        int  temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};
// @lc code=end

