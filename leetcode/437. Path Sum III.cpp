/**
* @Author: lcy
* @Date:   2016-10-30T23:35:05-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// You are given a binary tree in which each node contains an integer value.
//
// Find the number of paths that sum to a given value.
//
// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
// Example:
//
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
//
// Return 3. The paths that sum to 8 are:
//
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // use unordered_map to record previous path sum, very smart! must learn
 // pay attention to ?: use () to get it right
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> mp;
        return helper(root, mp, sum, 0);
    }
    int helper(TreeNode* root, unordered_map<int, int>& mp, int sum, int pre){
        if(!root) return 0;
        root->val += pre;
        int res = 0;
        res += (root->val == sum) + (mp.count(root->val - sum) ? mp[root->val -sum]:0); //!!!
        mp[root->val]++;
        res += helper(root->right, mp, sum, root->val) + helper(root->left, mp, sum, root->val);
        mp[root->val]--;
        return res;

    }
};
