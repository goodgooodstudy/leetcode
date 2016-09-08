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
    int closestValue(TreeNode* root, double target) {
        if(root ==NULL) return 0;
        int tmp;
        int cur = root->val;
        if(target < cur && root->left ){
            tmp = closestValue(root->left, target);
            return abs(tmp-target) < abs(cur - target) ? tmp : cur;
        }
        else if(root->right){
               tmp = closestValue(root->right, target);
            return abs(tmp-target) < abs(cur - target)?tmp:cur;
        }
        else{
            return cur;
        }
        
    }
};
