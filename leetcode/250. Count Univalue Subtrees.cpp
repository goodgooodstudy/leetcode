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
private:
    int total;
public:
    int countUnivalSubtrees(TreeNode* root) {
        total = 0;
        if(root)isUnival(root);
        return total;
    }
    bool isUnival(TreeNode* root){
        if(!root->left && !root->right){
            total++;
            return true;
        }
        if(root->left && root->right){
            bool l = isUnival(root->left);
            bool r = isUnival(root->right);
            if(l &&r && root->left->val == root->right->val && root->left->val == root->val){
                total++;
                return true;
            }
            else return false;
        }
        else if(root->left){
            if(isUnival(root->left) && root->left->val == root->val){
                total++;
                return true;
            }
            else return false;
        }
        else{
            if(isUnival(root->right) && root->right->val == root->val){
                total++;
                return true;
            }
            else return false;
        }
    }
};
