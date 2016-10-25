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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
            vector<int> list;
            inorder(root, list);
            while(list.size() > k){
                if(abs(list.front() - target) < abs(list.back()-target))list.erase(list.end()-1);
                else list.erase(list.begin());
            }
            return list;
            

    }
    void inorder(TreeNode* root, vector<int>& list){
        if(root==NULL) return ;
        inorder(root->left,list);
        list.push_back(root->val);
        inorder(root->right,list);
    }
};
