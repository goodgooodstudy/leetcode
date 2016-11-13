/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> sk;
        vector<int> rst;
        while(!sk.empty() || root){
            while(root){
                sk.push(root);
                root = root->left;
            }
            if(!sk.empty()){
                rst.push_back(sk.top()->val);
                root = sk.top()->right;
                sk.pop();
            }
            
        }
        return rst;
    }
};
class Solution {
public:
  // recursive one
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(result, root);
        return result;

    }
    void inorder(vector<int>& path, TreeNode *root){
        if(root!=NULL){
            inorder(path, root->left);
            path.push_back(root->val);
            inorder(path,root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<const TreeNode *> s;
        const TreeNode* p = root;
        while(!s.empty() || p!=NULL){
            if(p != NULL){
                s.push(p);
                p = p ->left;
            }
            else{
                p = s.top();
                s.pop();
                result.push_back(p -> val);
                p = p->right;
            }
        }
        return result;
    }
};
