#include <iostream>
#include <vector>
using std::vector;
#include <algorithm>
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int quickSelect(vector<int>& nums,int left,int right,int k){
        if(left == right){
            return nums[left]; // 也可以写成 return nums[right];
        }

        int pivotIndex = partition(nums,left,right);

        if(k == pivotIndex){
            return nums[k];
        }
        else if(k < pivotIndex){
            return quickSelect(nums,left,pivotIndex - 1,k);
        }else{
            return quickSelect(nums,pivotIndex + 1,right,k);
        }
    }

    int partition(vector<int>& nums,int left,int right){
        int pivot = nums[right];
        int storeIndex = left;
        for(int i = left;i < right;i++){
            if(nums[i] < pivot){
                std::swap(nums[storeIndex],nums[i]);
                storeIndex ++ ;
            }
        }
        std::swap(nums[storeIndex],nums[right]);
        return storeIndex;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size() - 1,nums.size() -k);
    }
};
// @lc code=end

