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
        int closest = root->val;
        while(root){
            if(abs(closest-target) >= abs(root->val - target))
                closest = root->val;
            root = target < root->val ? root->left:root->right;
        }
        
        return closest;
     
     
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
