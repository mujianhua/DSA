/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 private:
  const string letterMap[10] = {
      "",      // 0
      "",      // 1
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz",  // 9
  };

  vector<string> result;
  string path;

 public:
  void backtracking(const string& digits, int index) {
    if (index == digits.size()) {
      result.push_back(path);
      return;
    }
    int digit = digits[index] - '0';
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); i++) {
      path.push_back(letters[i]);
      backtracking(digits, index + 1);
      path.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    result.clear();
    path.clear();
    if (digits.size() == 0) {
      return result;
    }
    backtracking(digits, 0);
    return result;
  }
};
// @lc code=end
