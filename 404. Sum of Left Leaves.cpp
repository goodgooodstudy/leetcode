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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);
        int total = 0;
        if(root->left&&isleaf(root->left)) total += root->left->val;
        total = total + left + right;
        return total;
    }
    bool isleaf(TreeNode* root){
        if(root->left == NULL && root->right ==NULL) return true;
        return false;
    }
};
