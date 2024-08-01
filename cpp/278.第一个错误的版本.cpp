#include <iostream>
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// 假设有一个API：bool isBadVersion(int version);
// 你可以调用它来判断一个版本是否有错误
int firstBad; // 全局变量，表示第一个错误的版本

bool isBadVersion(int version) {
    return version >= firstBad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) { // 循环直至区间左右端点相同
            int mid = left + (right - left) / 2; // 防止计算时溢出
            if (isBadVersion(mid)) {
                right = mid; // 答案在区间 [left, mid] 中
            } else {
                left = mid + 1; // 答案在区间 [mid+1, right] 中
            }
        }
        // 此时有 left == right，区间缩为一个点，即为答案
        return left;
    }
};


// @lc code=end
int main() {
    firstBad = 4; // 设定第一个错误的版本
    Solution solution;
    int n = 10;
    std::cout << "第一个错误的版本是: " << solution.firstBadVersion(n) << std::endl;
    return 0;
}
