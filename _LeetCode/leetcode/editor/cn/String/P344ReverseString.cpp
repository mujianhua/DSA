//Write a function that reverses a string. The input string is given as an 
//array of characters s. 
//
// You must do this by modifying the input array in-place with O(1) extra 
//memory. 
//
// 
// Example 1: 
// Input: s = ["h","e","l","l","o"]
//Output: ["o","l","l","e","h"]
// Example 2: 
// Input: s = ["H","a","n","n","a","h"]
//Output: ["h","a","n","n","a","H"]
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁵ 
// s[i] is a printable ascii character. 
// 
// Related Topics 递归 双指针 字符串 👍 521 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size()-1; i < s.size()/2; i++,j--){
            swap(s[i],s[j]);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution S;
    return 0;
}
