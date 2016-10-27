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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(!root) return rst;
        stack<TreeNode*> curLevel ;
        stack<TreeNode*> nextLevel;
        curLevel.push(root);
        bool left2right = true;
        while(!curLevel.empty()){
            vector<int> cur_rst;
            while(!curLevel.empty()){
                TreeNode* tmp = curLevel.top();
                curLevel.pop();
                cur_rst.push_back(tmp->val);
                if(left2right){
                    if(tmp->left) nextLevel.push(tmp->left);
                    if(tmp->right)nextLevel.push(tmp->right);
                }
                else{
                    if(tmp->right)nextLevel.push(tmp->right);
                    if(tmp->left) nextLevel.push(tmp->left);
                }
            }
            rst.push_back(cur_rst);
            stack<TreeNode*> tmp = curLevel;
            curLevel = nextLevel;
            nextLevel = tmp;
            left2right = !left2right;
        }
        return rst;
        
    }
};
