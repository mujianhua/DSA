/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;
  void backtracking(vector<int> candidates, int targetSum, int sum,
                    int startindex) {
    if (sum > targetSum) {
      return;
    }
    if (sum == targetSum) {
      result.push_back(path);
      return;
    }
    for (int i = startindex; i < candidates.size(); i++) {
      if (i > startindex && candidates[i] == candidates[i - 1]) {
        continue;  // 与39题的区别
      }
      path.push_back(candidates[i]);
      sum += candidates[i];
      backtracking(candidates, targetSum, sum, i + 1);
      path.pop_back();
      sum -= candidates[i];
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    result.clear();
    path.clear();
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return result;
  }
};
// @lc code=end
