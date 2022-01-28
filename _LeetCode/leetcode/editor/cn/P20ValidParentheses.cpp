//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']
//', determine if the input string is valid. 
//
// An input string is valid if: 
//
// 
// Open brackets must be closed by the same type of brackets. 
// Open brackets must be closed in the correct order. 
// 
//
// 
// Example 1: 
//
// 
//Input: s = "()"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: s = "()[]{}"
//Output: true
// 
//
// Example 3: 
//
// 
//Input: s = "(]"
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of parentheses only '()[]{}'. 
// 
// Related Topics 栈 字符串 👍 2930 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        unordered_map<char, char> map{
                {')', '('},
                {']', '['},
                {'}', '{'}
        };
        stack<char> stk;
        for (char ch : s) {
            if (map.count(ch)) {
                if (stk.empty() || map[ch] != stk.top())
                    return false;
                stk.pop();
            } else
                stk.push(ch);
        }
        return stk.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    bool result = S.isValid("()");
    cout << result << '\n';
    return 0;
}
