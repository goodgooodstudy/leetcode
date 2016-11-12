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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rst;
        if(!root) return rst;
        stack<TreeNode*> sk;

        while(root){
            while(root){
                rst.push_back(root->val);
                sk.push(root);
                root = root->left;
            }
            while(!sk.empty() && root==NULL){
                root = sk.top()->right;
                sk.pop();
            }
        }
        return rst;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        const TreeNode* p;
        stack <const TreeNode *> s;
        p = root;
        if(p!=NULL) s.push(p);
        while(!s.empty()){
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if(p->right!=NULL) s.push(p->right);
            if(p->left!=NULL) s.push(p->left);
        }
        return result;
    }
};
