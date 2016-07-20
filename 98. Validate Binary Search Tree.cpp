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
        int i = INT_MIN;
        bool first = true;
        return isValid(root,i,first);
        
    }
    bool isValid(TreeNode* root, int& previous, bool& first){
        if(root == NULL) return true;
        if(isValid(root->left, previous,first) == false)return false;
        if(first== false && root->val <= previous )return false;
        previous = root->val;
        first = false;
        if(isValid(root->right, previous,first) == false) return false;
        return true;
    }
};
