//There is a car with capacity empty seats. The vehicle only drives east (i.e., 
//it cannot turn around and drive west). 
//
// You are given the integer capacity and an array trips where trips[i] = [
//numPassengersi, fromi, toi] indicates that the iᵗʰ trip has numPassengersi 
//passengers and the locations to pick them up and drop them off are fromi and toi 
//respectively. The locations are given as the number of kilometers due east from the 
//car's initial location. 
//
// Return true if it is possible to pick up and drop off all passengers for all 
//the given trips, or false otherwise. 
//
// 
// Example 1: 
//
// 
//Input: trips = [[2,1,5],[3,3,7]], capacity = 4
//Output: false
// 
//
// Example 2: 
//
// 
//Input: trips = [[2,1,5],[3,3,7]], capacity = 5
//Output: true
// 
//
// 
// Constraints: 
//
// 
// 1 <= trips.length <= 1000 
// trips[i].length == 3 
// 1 <= numPassengersi <= 100 
// 0 <= fromi < toi <= 1000 
// 1 <= capacity <= 10⁵ 
// 
// Related Topics 数组 前缀和 排序 模拟 堆（优先队列） 👍 145 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // Mark  差分数组改编!!!!!!!!!!!!!!  好巧~
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vector<int> nums(1001);
        for (auto &trip:trips) {
            nums[trip[1]] += trip[0];
            nums[trip[2]] -= trip[0];
        }
        int count = 0;
        for (auto i :nums) {
            count += i;
            if (count > capacity)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    vector<vector<int>> test{{2, 1, 5},
                             {3, 5, 7}};
    bool res = S.carPooling(test, 3);
    cout << res << '\n';
    return 0;
}
