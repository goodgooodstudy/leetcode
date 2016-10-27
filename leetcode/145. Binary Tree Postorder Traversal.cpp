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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        const TreeNode *p, *q;
        stack<const TreeNode*> s;
        p = root;
        do{
            while(p != NULL){
                s.push(p);
                p = p->left;
            }
            q = NULL;
            while(!s.empty()){
                p = s.top();
                s.pop();
                if(p->right == q){
                    result.push_back(p->val);
                    q = p;
                }
                else{
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        }while(!s.empty());
        return result;
    }
};
