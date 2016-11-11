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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) return sum == root->val;
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum-root->val);
    }
};


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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return helper(root,0, sum);
    }
    bool helper(TreeNode* root, int cum, int target){
        cum += root->val;
        if(!root->left && !root->right){ // cannot judge null, because, it may be in the middle which cannot behave as a judge
            if(cum == target) return true;
            else return false;
        }
        if(root->left && helper(root->left, cum, target)) return true;
        if(root->right && helper(root->right, cum, target)) return true;
        return false;
    }
};
