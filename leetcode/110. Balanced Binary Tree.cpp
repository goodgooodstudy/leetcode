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
    bool isBalanced(TreeNode* root) {
        return findDepth(root) == -1?false:true;
    }
    int findDepth(TreeNode* root){
        if(!root) return 0;
        int l = findDepth(root->left);
        if(l == -1) return -1;
        int r = findDepth(root->right);
        if( r == -1) return -1;

        if(abs(l-r) > 1) return -1;
        return max(l,r)+1;
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
    bool isBalanced(TreeNode* root) {
        int length = 0;
        return helper(root, length);
    }
    bool helper(TreeNode* root, int& length){
        if(!root){
            length = 0;
            return true;
        }
        int left = 0, right = 0;
        if(!helper(root->left, left)) return false;
        if(!helper(root->right, right)) return false;
        if(abs(left-right) > 1) return false;
        length = max(left, right)+1;
        return true;
    }
};
