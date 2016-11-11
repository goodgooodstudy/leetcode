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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL, *first = NULL, *second = NULL;
        findNode(root, pre, first, second);
        int value = first->val;
        first->val = second->val;
        second->val = value;
        
    }
    void findNode(TreeNode* root, TreeNode*& pre, TreeNode*& first, TreeNode*& second){
        if(!root)return;
        findNode(root->left, pre, first, second);
        
        if(pre != NULL && pre->val > root->val){
            if(first == NULL) first = pre;
            if(first!= NULL) second = root;
        }
        pre = root;
        findNode(root->right, pre, first, second);
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
