//Given the root of a binary tree, return the preorder traversal of its nodes' 
//values. 
//
// 
// Example 1: 
//
// 
//Input: root = [1,null,2,3]
//Output: [1,2,3]
// 
//
// Example 2: 
//
// 
//Input: root = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: root = [1]
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 100]. 
// -100 <= Node.val <= 100 
// 
//
// 
// Follow up: Recursive solution is trivial, could you do it iteratively? 
// Related Topics 栈 树 深度优先搜索 二叉树 👍 724 👎 0

#include <iostream>
#include <bits/stdc++.h>
#include "../leetcode_include.h"

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
//    void pre(TreeNode *root, vector<int> &res){
//        if (!root)
//            return;
//        res.push_back(root->val);
//        pre(root->left,res);
//        pre(root->right,res);
//    }
    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int> res;
//        pre(root, res);
//        return res;
        stack<TreeNode *> stk;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution S;
    return 0;
}
