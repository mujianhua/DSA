/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> result;

  bool isValid(string &s, int start, int end) {
    if (start > end) {
      return false;
    }
    if (s[start] == '0' && start != end) {
      return false;
    }
    int sum = 0;
    for (int i = start; i <= end; i++) {
      if (s[i] < '0' || s[i] > '9') {
        return false;
      }
      sum = sum * 10 + s[i] - '0';
      if (sum > 255) {
        return false;
      }
    }
    return true;
  }

  void backTracking(string &s, int start_index, int point_num) {
    if (point_num == 3) {
      if (isValid(s, start_index, s.size() - 1)) {
        result.push_back(s);
      }
      return;
    }
    for (int i = start_index; i < s.size(); i++) {
      if (isValid(s, start_index, i)) {
        s.insert(s.begin() + i + 1, '.');
        point_num++;
        backTracking(s, i + 2, point_num);
        point_num--;
        s.erase(s.begin() + i + 1);
      } else
        return;
    }
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    result.clear();
    if (s.size() < 4 || s.size() > 12) return result;
    backTracking(s, 0, 0);
    return result;
  }
};
// @lc code=end
