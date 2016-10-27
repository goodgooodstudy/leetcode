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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isValid(root,prev);
        
    }
    bool isValid(TreeNode* root, TreeNode*& previous){
        if(root == NULL) return true;
        if(isValid(root->left, previous) == false)return false;
        if(previous!= NULL && root->val <= previous->val )return false;
        previous = root;
        if(isValid(root->right, previous) == false) return false;
        return true;
    }
};
