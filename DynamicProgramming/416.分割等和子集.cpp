/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum = sum + nums[i];
    }
    if (sum % 2 == 1) return false;
    int target = sum / 2;

    vector<int> dp(10001, 0);
    for (int i = 0; i < nums.size(); i++) {      // 遍历物品
      for (int j = target; j >= nums[i]; j--) {  // 遍历背包
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }

    if (dp[target] == target) return true;
    return false;
  }
};
// @lc code=end
