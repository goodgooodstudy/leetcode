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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> rst;
        vector<int> cur;
        pathSum(root,sum,rst,cur);
        return rst;
    }
    void pathSum(TreeNode* root, int sum, vector<vector<int>>& rst, vector<int>& cur){
        if(root == NULL) return;
        cur.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == root->val) rst.push_back(cur);
        }
        pathSum(root->left, sum-root->val, rst, cur);
        pathSum(root->right, sum - root->val, rst, cur);
        cur.pop_back();
    }
};
