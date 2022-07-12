/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int> candidates, int targetSum, int sum, int startindex) {
    if (sum > targetSum) {
      return;
    }
    if (sum == targetSum) {
      result.push_back(path);
      return;
    }
    for (int i = startindex; i < candidates.size(); i++) {
      path.push_back(candidates[i]);
      sum += candidates[i];
      backtracking(candidates, targetSum, sum, i);
      path.pop_back();
      sum -= candidates[i];
    }
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    result.clear();
    path.clear();
    backtracking(candidates, target, 0, 0);
    return result;
  }
};
// @lc code=end
