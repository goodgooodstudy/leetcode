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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res; // do not forget again!!!!

        queue<TreeNode*> cur;
        cur.push(root);
   

        while(cur.size()>0){
            int n = cur.size();
            for(int i = 0; i<n; i++){
                TreeNode* tmp = cur.front();
                cur.pop();
                if(i == n-1) res.push_back(tmp->val);
                if(tmp->left)cur.push(tmp->left);
                if(tmp->right)cur.push(tmp->right);
            }

        }
        return res;
        
    }
};

class Solution {
private:
    void dfs(TreeNode* node, vector<int>&res,int level){
        if(!node)return;
        if(level == res.size()) res.push_back(node->val);
        dfs(node->right,res,level+1);
        dfs(node->left,res,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root,res,0);
        return res;
        
    }
};
