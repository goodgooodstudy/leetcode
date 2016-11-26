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
        stack<TreeNode*> sk;
        vector<int> rst;
        TreeNode* prev = NULL;

        while(root){
            while(root){
                sk.push(root);
                root = root->left;
            }

            while(!sk.empty()&&!root){
                TreeNode* top =sk.top();
                if(top->right && top->right != prev){
                    root = top->right;
                }
                else{
                    sk.pop();
                    prev = top;
                    rst.push_back(top->val);
                }

            }
        }
        return rst;

    }
};
 vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* lastNode = NULL, *curNode = root;
        stack<TreeNode*> sk;
        vector<int> rst;
        while(!sk.empty() || curNode){
            while(curNode){
                sk.push(curNode);
                curNode = curNode->left;
            }
            if(!sk.empty()){
                TreeNode* top = sk.top();
                if(top->right && top->right != lastNode){
                    curNode = top->right;
                }
                else{
                    rst.push_back(top->val);
                    lastNode = top;
                    sk.pop();
                }

            }
        }
        return rst;

    }
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
