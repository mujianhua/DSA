/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    vector<int> dp(15001, 0);
    int sum = 0;
    for (int i = 0; i < stones.size(); i++) {
      sum += stones[i];
    }
    int target = sum/2;
    for (int i = 0; i < stones.size(); i++) {
      for (int j = target; j >= stones[i]; j--) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    // 将石头分为两堆,比较两堆质量是否相等.
    return sum - dp[target] - dp[target];
  }
};
// @lc code=end
