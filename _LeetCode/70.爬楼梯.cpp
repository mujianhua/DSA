/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    // 爬到第n层可以从n-1层上1层，也可以从n-2层上两层
    if (n <= 1) return n;
    int dp[3];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      int sum = dp[1] + dp[2];
      dp[1] = dp[2];
      dp[2] = sum;
    }
    return dp[2];
  }
};
// @lc code=end
