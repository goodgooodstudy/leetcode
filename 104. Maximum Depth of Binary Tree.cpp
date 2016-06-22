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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> s;
        if(!root) return 0;
        s.push(root);
        int res = 0;
        while(!s.empty()){
            ++res;
            int n = s.size();
            for(int i = 0; i < n; i++){
                auto p = s.front();
                s.pop();
                if(p->left!=NULL) s.push(p->left);
                if(p->right!=NULL) s.push(p->right);

            }
        }
        return res;
        
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ==NULL?0:max(maxDepth(root->left),maxDepth(root->right))+1;
        
    }
};
