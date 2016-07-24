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
    bool isBalanced(TreeNode* root) {
        return findDepth(root) == -1?false:true;
    }
    int findDepth(TreeNode* root){
        if(!root) return 0;
        int l = findDepth(root->left);
        if(l == -1) return -1;
        int r = findDepth(root->right);
        if( r == -1) return -1;
        
        if(abs(l-r) > 1) return -1;
        return max(l,r)+1;
    }
};
