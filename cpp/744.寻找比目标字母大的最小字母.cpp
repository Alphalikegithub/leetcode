#include <vector>
using std::vector;
/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
//方法二：二分查找
/*
首先比较目标字母和列表中的最后一个字母（列表letters是按非递减顺序排序）
，当目标字母大于或等于列表中的最后一个字母时，答案是列表的首个字母。、
当目标字母小于列表中的最后一个字母时，列表中最后一个元素之前的元素都比他大，
可以使用二分查找得到比目标字母大的最小字母。

初始时，二分查找的范围是整个列表的下标范围。每次比较当前下标处的字母和目标字母，
如果当前下标处的字母大于目标字母，则在当前下标以及当前下标的左侧继续查找，
否则在当前下标的右侧继续查找。
*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        int ret = 0;
        while(left <= right){
            int m = left + (right - left) / 2;\
            if(letters[m] <= target){
                left = m + 1;
            }else{
                ret = m;
                right  = m - 1;
            }
        }
        return letters[ret];
    }
};
// @lc code=end

