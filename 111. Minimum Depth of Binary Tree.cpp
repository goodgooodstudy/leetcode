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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ldepth = minDepth(root->left);
        int rdepth = minDepth(root->right);
        if(ldepth == 0 && rdepth == 0){
            return 1;
        }
        if(ldepth == 0){
            ldepth = INT_MAX;
        }
        if(rdepth == 0){
            rdepth = INT_MAX;
        }
        return min(ldepth, rdepth)+1;
        
    }
};
