#include <vector>
#include <algorithm>
using std::vector;
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *          
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int child = 0;//能吃饱的孩子的数量
        int cookie = 0;
        while(child < g.size() && cookie < s.size()){
            if(g[child] <= s[cookie++]){
                child++;
            }
        }
        return child;
    }
};
// @lc code=end

