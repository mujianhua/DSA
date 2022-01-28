//Given two strings s and t, return true if t is an anagram of s, and false 
//otherwise. 
//
// An Anagram is a word or phrase formed by rearranging the letters of a 
//different word or phrase, typically using all the original letters exactly once. 
//
// 
// Example 1: 
// Input: s = "anagram", t = "nagaram"
//Output: true
// Example 2: 
// Input: s = "rat", t = "car"
//Output: false
// 
// 
// Constraints: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s and t consist of lowercase English letters. 
// 
//
// 
// Follow up: What if the inputs contain Unicode characters? How would you 
//adapt your solution to such a case? 
// Related Topics 哈希表 字符串 排序 👍 487 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++)
            record[s[i] - 'a']++;
        for (int j = 0; j < t.size(); j++)
            record[t[j] - 'a']--;
        for (int k = 0; k < 26; k++) {
            if (record[k] != 0)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    string test1 = "abcd";
    string test2 = "dbca";
    bool res = S.isAnagram(test1, test2);
    cout << res << '\n';
    return 0;
}
