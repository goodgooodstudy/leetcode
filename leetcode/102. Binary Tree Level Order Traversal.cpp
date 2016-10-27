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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        queue<const TreeNode*> current, next;
        vector<int> level;
        current.push(root);
        while(!current.empty()){
            while(!current.empty()){
                const TreeNode * tmp = current.front();
                current.pop();
                level.push_back(tmp->val);
                if(tmp->left) next.push(tmp->left);
                if(tmp->right) next.push(tmp->right);
            }
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        return result;
        
        
    }
};
