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
        vector<int> rst = helper(root);
        return max(rst[0],rst[1]);
        
    }
    vector<int> helper(TreeNode* root){
        if(!root) return vector<int>(2,0);
        int total = 0;
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        vector<int> res(2,0);
        res[0] = max(left[0], left[1])+max(right[0], right[1]);
        res[1] = root->val + left[0]+right[0];
        return res;
        
        
    }
};
