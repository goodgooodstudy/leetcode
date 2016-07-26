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
    TreeNode* lastnode = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* right = root->right;
        if(lastnode != NULL){
            lastnode->left=NULL;
            lastnode->right = root;
        }
        lastnode = root;
        flatten(root->left);
        flatten(right);
        
    }
};
