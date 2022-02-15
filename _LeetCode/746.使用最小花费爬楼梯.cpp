/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i=2; i<cost.size(); ++i){
      dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    // 最后一步不消耗体力
    return min(dp[cost.size()-2], dp[cost.size()-1]);
  }
};
// @lc code=end
