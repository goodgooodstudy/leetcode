/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// still cannot come up with....
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int hl = 0, hr =0;
        TreeNode* l = root,*r = root;
        while(l){l=l->left;hl++;}
        while(r){r=r->right;hr++;}
        if(hl == hr) return pow(2,hl)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
        
    }
};
