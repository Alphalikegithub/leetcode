/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0,right = numbers.size() -1;//left指针在最左边 right指针在最右边
        while(left <= right){
            if(numbers[left] + numbers[right] == target){
                return {left + 1,right + 1};
            }
            else if(numbers[left] + numbers[right] < target){
                left ++;
            }
            else
            {
                right --;
            }
        }
        return {-1,-1};
    }
};
// @lc code=end

