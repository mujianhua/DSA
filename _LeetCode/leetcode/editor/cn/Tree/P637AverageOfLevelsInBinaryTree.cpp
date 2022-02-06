//Given the root of a binary tree, return the average value of the nodes on 
//each level in the form of an array. Answers within 10⁻⁵ of the actual answer will 
//be accepted.
// 
// Example 1: 
//
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: [3.00000,14.50000,11.00000]
//Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, 
//and on level 2 is 11.
//Hence return [3, 14.5, 11].
// 
//
// Example 2: 
//
// 
//Input: root = [3,9,20,15,7]
//Output: [3.00000,14.50000,11.00000]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 10⁴]. 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 309 👎 0

#include <iostream>
#include <bits/stdc++.h>
#include "leetcode_include.h"

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        queue<TreeNode *> q;
        if (root != nullptr)
            q.push(root);
        while (!q.empty()) {
            int size = q.size();
            double sum = 0.0;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                sum += node->val;
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            double average = sum / size;
            res.push_back(average);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    return 0;
}
