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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->right&&!root->left) return 1;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        int h = 1;
        if(!root->left) h += r;
        else if(!root->right) h += l;
        else h += min(l,r);
        return h;
        
    }
};
