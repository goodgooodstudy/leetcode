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
    int longestConsecutive(TreeNode* root) {
        // if(!root) return 0;
        return search(root, nullptr, 0);
        
    }
    int search(TreeNode* root, TreeNode* parent, int len){
        if(!root) return len;
        len = (parent && (parent->val + 1 == root->val))? len+1: 1;
        return max(len, max(search(root->left, root, len), search(root->right, root,len)));
    }
};
