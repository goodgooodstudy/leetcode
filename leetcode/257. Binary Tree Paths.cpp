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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        dfs(root,res,to_string(root->val));
        return res;
    }
    void dfs(TreeNode* root, vector<string>& res, string n){
        if(!root->left && !root->right){
            res.push_back(n);
            return;
        }
        if(root->left)dfs(root->left, res, n+"->"+to_string(root->left->val));
        if(root->right)dfs(root->right, res, n+"->"+to_string(root->right->val));
    }
};
