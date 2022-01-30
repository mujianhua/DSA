//Given an m x n matrix, return all elements of the matrix in spiral order. 
//
// 
// Example 1: 
//
// 
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]
// 
//
// Example 2: 
//
// 
//Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
// Related Topics 数组 矩阵 模拟 👍 967 👎 0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 0 || cols == 0)
            return {};
        vector<int> res;
        int left = 0, right = cols - 1;
        int top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int col = left; col <= right; col++)
                res.push_back(matrix[top][col]);
            for (int row = top + 1; row <= bottom; row++)
                res.push_back(matrix[row][right]);
            if (left < right && top < bottom) {
                for (int col = right - 1; col > left; col--)
                    res.push_back(matrix[bottom][col]);
                for (int row = bottom; row > top; row--)
                    res.push_back(matrix[row][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    vector<vector<int>> test(4, vector<int>(3, 0));
    test = {{1,  2,  3},
            {11, 12, 13},
            {21, 22, 23},
            {31, 32, 33}};
    vector<int> result = S.spiralOrder(test);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << '\t';
    }
    return 0;
}
