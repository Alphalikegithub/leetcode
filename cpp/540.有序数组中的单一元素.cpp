#include <vector>
using std::vector;
/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ,r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(mid % 2 == 0){
                if(mid + 1 < n && nums[mid] == nums[mid + 1]){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }else{
                if(mid - 1 >= 0 && nums[mid - 1] == nums[mid]){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
        }
        return nums[r];
    }
};
// @lc code=end

