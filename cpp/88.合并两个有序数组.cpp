/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0,p2 = 0;
        int sorted[m + n];
        int cur;
        while(p1 < m || p2 < n){
            if(p1 == m){
                //如果 p1 达到了 nums1 的末尾，说明 nums1 的元素已经全部处理完，只需将 nums2 的元素逐一加入 sorted
                cur = nums2[p2++];
            }else if(p2 == n){
                //如果 p2 达到了 nums2 的末尾，说明 nums2 的元素已经全部处理完，只需将 nums1 的元素逐一加入 sorted
                cur = nums1[p1++];
            }else if(nums1[p1] < nums2[p2]){
                //如果 nums1 当前元素小于 nums2 当前元素，将 nums1 当前元素加入 sorted。
                cur = nums1[p1++];
            }else{
                //否则将 nums2 当前元素加入 sorted
                cur = nums2[p2++];
            }
            // 将当前元素 cur 放入 sorted 数组的正确位置。
            sorted[p1 + p2 - 1] = cur;
        }
        //循环遍历 sorted 数组。nums1[i] = sorted[i]; 将 sorted 数组的元素复制回 nums1 中。
        for(int i = 0;i != m + n;++ i){
            nums1[i] = sorted[i];
        }
    }
};
// @lc code=end

