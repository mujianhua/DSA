//There are n flights that are labeled from 1 to n. 
//
// You are given an array of flight bookings bookings, where bookings[i] = [
//firsti, lasti, seatsi] represents a booking for flights firsti through lasti (
//inclusive) with seatsi seats reserved for each flight in the range. 
//
// Return an array answer of length n, where answer[i] is the total number of 
//seats reserved for flight i. 
//
// 
// Example 1: 
//
// 
//Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
//Output: [10,55,45,25,25]
//Explanation:
//Flight labels:        1   2   3   4   5
//Booking 1 reserved:  10  10
//Booking 2 reserved:      20  20
//Booking 3 reserved:      25  25  25  25
//Total seats:         10  55  45  25  25
//Hence, answer = [10,55,45,25,25]
// 
//
// Example 2: 
//
// 
//Input: bookings = [[1,2,10],[2,2,15]], n = 2
//Output: [10,25]
//Explanation:
//Flight labels:        1   2
//Booking 1 reserved:  10  10
//Booking 2 reserved:      15
//Total seats:         10  25
//Hence, answer = [10,25]
//
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 2 * 10⁴ 
// 1 <= bookings.length <= 2 * 10⁴ 
// bookings[i].length == 3 
// 1 <= firsti <= lasti <= n 
// 1 <= seatsi <= 10⁴ 
// 
// Related Topics 数组 前缀和 👍 301 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // Mark 差分!!!!!!!!!!
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> diff(n);
        for (auto &booking :bookings) {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            diff[booking[0] - 1] += booking[2];
            if (booking[1] < n)
                diff[booking[1]] -= booking[2];
        }
        for (int i = 1; i < n; ++i) {
            diff[i] = diff[i - 1] + diff[i];
        }
        return diff;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    vector<vector<int>> bookings{{1, 2, 10},
                                 {2, 3, 20},
                                 {2, 5, 25}};
    vector<int> result = S.corpFlightBookings(bookings, 5);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}

//    class Difference {
//    private:
//        vector<int> diff;
//    public:
//        Difference(vector<int> &nums) {
//            if (nums.size() > 0) {
//                diff.resize(nums.size());
//                diff[0] = nums[0];
//                for (int i = 1; i < nums.size(); i++)
//                    diff[i] = nums[i] - nums[i - 1];
//            }
//        }
//
//        void increment(int i, int j, int val) {
//            diff[i] += val;
//            if (j + 1 < diff.size())
//                diff[j + 1] -= val;
//        }
//
//        vector<int> &result() {
//            vector<int> res;
//            res.resize(diff.size());
//            res[0] = diff[0];
//            for (int i = 1; i < diff.size(); i++)
//                res[i] = res[i - 1] + diff[i];
//            return res;
//        }
//    };
