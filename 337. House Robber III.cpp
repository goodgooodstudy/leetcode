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
    int rob(TreeNode* root) {
        int l,r;
        return tryrob(root,l,r);
       
    }
    int tryrob(TreeNode* root,int&l, int&r){
        if(!root) return 0;
        int ll = 0, lr = 0, rl=0,rr=0;
        l = tryrob(root->left,ll,lr);
        r = tryrob(root->right,rl,rr);
        return max(l+r, ll+lr+rl+rr+root->val);
    }
};
