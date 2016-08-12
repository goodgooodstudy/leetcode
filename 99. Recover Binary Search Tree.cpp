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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
public:

    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && second){
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
    
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        
        if(first==NULL && root->val <= pre->val){
            first = pre;
        }
        if(first!=NULL && root->val <= pre->val){
            second = root;
        }
        pre = root;
        
        inorder(root->right);
    }
};
