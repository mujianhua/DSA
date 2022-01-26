//Given a positive integer n, generate an n x n matrix filled with elements 
//from 1 to n² in spiral order. 
//
// 
// Example 1: 
//
// 
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: [[1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 矩阵 模拟 👍 580 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int start_x = 0, start_y = 0;
        int loop = n / 2;
        int offset = 1;// offset 控制每一圈的遍历长度！
        int count = 1;
        while (loop--) {
            int i = start_x;
            int j = start_y;
            for (j = start_y; j < n - offset + start_y; j++) {
                res[start_x][j] = count++;
            }
            for (i = start_x; i < n - offset + start_x; i++) {
                res[i][j] = count++;
            }
            for (; j > start_y; j--) {
                res[i][j] = count++;
            }
            for (; i > start_x; i--) {
                res[i][start_y] = count++;
            }
            start_x++;
            start_y++;
            offset += 2;
        }
        if (n % 2) {
            res[n / 2][n / 2] = count;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    vector<vector<int>> result = S.generateMatrix(5);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            cout << result[i][j] << '\t';
            if (j == 4)
                cout << '\n';
        }

    return 0;
}
