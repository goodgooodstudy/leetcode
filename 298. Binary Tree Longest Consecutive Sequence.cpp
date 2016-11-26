/**
* @Author: lcy
* @Date:   2016-10-27T19:00:40-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;





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
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
    int helper(TreeNode* cur, TreeNode* parent, int len){
         if(cur == NULL) return len;
        len = (parent && cur->val == parent->val+1) ? len+1 : 1;
        int left = helper(cur->left, cur, len);
        int right = helper(cur->right, cur, len);
        return max(len, max(left, right));
    }

};
