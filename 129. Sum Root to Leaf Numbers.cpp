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
    int sumNumbers(TreeNode* root) {
        int all = 0;
        int sum = 0;
        sumNumbers(root,all,sum);
        return all;
    }
    void sumNumbers(TreeNode* root, int& all, int sum){
        if(root == NULL) return;
        sum = sum*10 + root->val;
        if(!root->left && !root->right){
            all+=sum;
            return;
        } 
        sumNumbers(root->left, all, sum);
        sumNumbers(root->right, all, sum);
        
    }
};
