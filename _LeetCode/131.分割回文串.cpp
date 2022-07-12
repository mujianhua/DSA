/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> path;
  vector<vector<string>> result;

  bool isPalindrome(string &s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }

  void backTracking(string &s, int start_index) {
    if (start_index >= s.size()) {
      // 如果起始值大于s的大小,说明已经找到一组解决方案
      result.push_back(path);
      return;
    }
    for (int i = start_index; i < s.size(); i++) {
      if (isPalindrome(s, start_index, i)) {
        path.push_back(s.substr(start_index, i - start_index + 1));
      } else {
        continue;
      }
      backTracking(s, i + 1);  // ........
      path.pop_back();
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    path.clear();
    result.clear();
    backTracking(s, 0);
    return result;
  }
};
// @lc code=end
