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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        vector<vector<int>> res;
        if(!root)return res;

        queue<pair<TreeNode*,int>> tmp;
        tmp.emplace(root,0);
        
        while(!tmp.empty()){
            auto cur = tmp.front();
            tmp.pop();
            mp[cur.second].push_back(cur.first->val);
            if(cur.first->left!=NULL){
                tmp.emplace(cur.first->left, cur.second-1);
            }
            if(cur.first->right!=NULL){
                tmp.emplace(cur.first->right, cur.second+1);
            }
            
        }
        
        
        for(auto c : mp){
            res.push_back(c.second);
        }
        return res;
    }
    // void helper(TreeNode* root, map<int, vector<int>>& res,int idx){
    //     if(root == NULL) return;
    //     res[idx].push_back(root->val);
    //     helper(root->left,  res, idx-1);
    //     helper(root->right, res, idx+1);
        
    // }
};
