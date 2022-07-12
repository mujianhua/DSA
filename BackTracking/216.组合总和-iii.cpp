/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(int targetSum, int k, int sum, int startindex) {
    if (sum > targetSum) {
      return;
    }
    if (path.size() == k) {
      if (sum == targetSum) {
        result.push_back(path);
      }
      return;
    }
    // 看题...
    // 是从1~9选数,不是1~n...
    for (int i = startindex; i <= 9 - (k - path.size()) + 1; i++) {
      sum += i;
      path.push_back(i);
      backtracking(targetSum, k, sum, i + 1);
      sum -= i;
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    result.clear();
    path.clear();
    backtracking(n, k, 0, 1);
    return result;
  }
};
// @lc code=end
