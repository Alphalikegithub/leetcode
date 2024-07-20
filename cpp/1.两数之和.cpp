/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        for(int i = 0; i <  nums.size();i++){
            int complment = target - nums[i];//计算差值
            auto it = hashtable.find(complment);
            if(it != hashtable.end())//表示找到了这样的元素
            {
                return {it->second,i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

