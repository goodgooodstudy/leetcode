/**
* @Author: lcy
* @Date:   2016-10-27T09:45:05-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 366. Find Leaves of Binary Tree   QuestionEditorial Solution  My Submissions
// Total Accepted: 7397
// Total Submissions: 13260
// Difficulty: Medium
// Contributors: Admin
// Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
//
// Example:
// Given binary tree
//           1
//          / \
//         2   3
//        / \
//       4   5
// Returns [4, 5, 3], [2], [1].
//
// Explanation:
// 1. Removing the leaves [4, 5, 3] would result in this tree:
//
//           1
//          /
//         2
// 2. Now removing the leaf [2] would result in this tree:
//
//           1
// 3. Now removing the leaf [1] would result in the empty tree:
//
//           []
// Returns [4, 5, 3], [2], [1].

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> rst;
        helper(rst, root);
        return rst;

    }
    int helper(vector<vector<int>>& rst, TreeNode* cur){
        if(!cur){
            return 1;
        }
        int level = 1;
        if(cur->left) level = max(helper(rst, cur->left), level);
        if(cur->right) level = max(helper(rst, cur->right), level);
        if(rst.size()< level) rst.resize(level);
        rst[level-1].push_back(cur->val);
        return level+1;
    }
};
