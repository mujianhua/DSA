//Given two strings s1 and s2, return true if s2 contains a permutation of s1, 
//or false otherwise. 
//
// In other words, return true if one of s1's permutations is the substring of 
//s2. 
//
// 
// Example 1: 
//
// 
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
// 
//
// Example 2: 
//
// 
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s1.length, s2.length <= 10⁴ 
// s1 and s2 consist of lowercase English letters. 
// 
// Related Topics 哈希表 双指针 字符串 滑动窗口 👍 550 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char n:s1)
            need[n]++;
        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char char_right = s2[right];
            right++;
            if (need.count(char_right)) {
                window[char_right]++;
                if (need[char_right] == window[char_right])
                    valid++;
            }
            while (right - left >= s1.size()) {
                if (valid == s1.size())
                    return true;
                char char_left = s2[left];
                left++;
                if (need.count(char_left)) {
                    if (need[char_left] == window[char_left])
                        valid--;
                    window[char_left]--;
                }
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    return 0;
}
