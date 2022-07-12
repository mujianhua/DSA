/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(int n, int k, int startindex) {
    if (path.size() == k) {
      result.push_back(path);
      return;
    }
    // 已有path.size()个元素
    // 还需(k - path.size())个元素
    // 至少要从n - (k - path.size()) + 1开始选取元素
    for (int i = startindex; i <= n - (k - path.size()) + 1; i++) {
      path.push_back(i);
      backtracking(n, k, i + 1);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    result.clear();
    path.clear();
    backtracking(n, k, 1);
    return result;
  }
};
// @lc code=end
