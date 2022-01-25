////Given an array of integers nums and an integer k, return the total number 
//of 
////continuous subarrays whose sum equals to k. 
////
//// 
//// Example 1: 
//// Input: nums = [1,1,1], k = 2
////Output: 2
//// Example 2: 
//// Input: nums = [1,2,3], k = 3
////Output: 2
//// 
//// 
//// Constraints: 
////
//// 
//// 1 <= nums.length <= 2 * 10⁴ 
//// -1000 <= nums[i] <= 1000 
//// -10⁷ <= k <= 10⁷ 
//// 
//// Related Topics 数组 哈希表 前缀和 👍 1284 👎 0
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // Mark  uncompletely 前缀和+哈希表优化...
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += nums[j];
                if (sum == k)
                    res++;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    vector<int> num;
    num = {1, 2 ,3};
    int res = S.subarraySum(num, 3);
    cout << res << '\n';
    return 0;
}
