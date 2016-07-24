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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rst;
        if(!root) return rst;
        vector<TreeNode*> curLevel;
        vector<TreeNode*> nextLevel;

        curLevel.push_back(root);
        while(!curLevel.empty()){
            vector<int> cur_rst;
            for(auto tmp:curLevel){
                cur_rst.push_back(tmp->val);
                if(tmp->left)nextLevel.push_back(tmp->left);
                if(tmp->right)nextLevel.push_back(tmp->right);
            }
            rst.push_back(cur_rst);
            vector<TreeNode*> tmp = curLevel;
            curLevel = nextLevel;
            nextLevel = tmp;
            nextLevel.clear();
        }
        reverse(rst.begin(),rst.end());
        return rst;
        
        
    }
};
