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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> sk;
        bool find = false;
        while(root || !sk.empty()){
            while(root){
                sk.push(root);
                root = root->left;
            }
            if(!sk.empty()){
                TreeNode* top = sk.top();
                if(find) return top;
                if(top == p){
                    find = true;
                }
                sk.pop();
                root =top->right;
            }
        }
        return NULL;
        
    }
};
