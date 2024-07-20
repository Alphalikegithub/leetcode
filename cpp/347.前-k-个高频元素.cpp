#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>  // for std::pair
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::greater;
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1.使用字典，统计每个元素出现的次数，元素为键，元素出现的次数为值
        unordered_map<int,int> frequencyMap;
        for(int num : nums){
            frequencyMap[num] ++;
        }
        //2.使用最小堆来维护频率最高的k个元素
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >  minHeap;

        for(auto& entry : frequencyMap){
            minHeap.push({entry.second,entry.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        //3.提取堆中的元素
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
    
};
// @lc code=end

