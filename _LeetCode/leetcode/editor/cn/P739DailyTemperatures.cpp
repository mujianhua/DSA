//Given an array of integers temperatures represents the daily temperatures, 
//return an array answer such that answer[i] is the number of days you have to wait 
//after the iᵗʰ day to get a warmer temperature. If there is no future day for 
//which this is possible, keep answer[i] == 0 instead. 
//
// 
// Example 1: 
// Input: temperatures = [73,74,75,71,69,72,76,73]
//Output: [1,1,4,2,1,1,0,0]
// Example 2: 
// Input: temperatures = [30,40,50,60]
//Output: [1,1,1,0]
// Example 3: 
// Input: temperatures = [30,60,90]
//Output: [1,1,0]
// 
// 
// Constraints: 
//
// 
// 1 <= temperatures.length <= 10⁵ 
// 30 <= temperatures[i] <= 100 
// 
// Related Topics 栈 数组 单调栈 👍 998 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            // stk.top() 上一次温度最大的一天
            // 栈从左向右看第一个
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }
            res[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    vector<int> test{89,62,70,58,47,47,46,76,100,70};
    vector<int> result = S.dailyTemperatures(test);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << '\t';
    }
    return 0;
}
