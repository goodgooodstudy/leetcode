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
    int largestBSTSubtree(TreeNode* root) {
        int mn,mx, size;
        isBst(root, mn,mx,size);
        return size;
    }
    bool isBst(TreeNode* root, int& mn, int& mx, int& size){
        if(!root){
            mn = INT_MAX;
            mx = INT_MIN;
            size = 0;
            return true;
        }
        
        int lmn, lmx, lsize, rmn, rmx, rsize;
        bool l = isBst(root->left, lmn, lmx, lsize);
        bool r = isBst(root->right, rmn, rmx, rsize);
        if(l && r){
            if((!root->left || root->val > lmx) &&(!root->right ||root->val < rmn)){
                mn = min(lmn, root->val);
                mx = max(rmx, root->val);
                size = lsize+rsize+1;
                return true;
            }
        }
        size = max(lsize, rsize);
        return false;
        
    }
};
