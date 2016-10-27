/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
//level order
    void connect(TreeLinkNode *root) {
        while(root!=NULL){
            TreeLinkNode* tmp = new TreeLinkNode(0);
            TreeLinkNode* cur = tmp;
            while(root!=NULL){
                if(root->left!=NULL){cur->next = root->left; cur = cur->next;}

                if(root->right!=NULL){cur->next=root->right;cur =cur->next;}
                root = root->next;

            }
            root = tmp->next;
            delete(tmp);
        }
    }
};
