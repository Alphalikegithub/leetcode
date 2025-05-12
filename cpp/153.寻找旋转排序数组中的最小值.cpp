/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
    while (l < h) {
        int m = l + (h - l) / 2;
        if (nums[m] <= nums[h]) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return nums[l];
    }
};
// @lc code=end

