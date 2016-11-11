/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
Credits:

记录tree的size， keep tree balance

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return Ksmallest(root,k);
    }
    int Ksmallest(TreeNode* root, int& k){
        if(!root)return -1;
        int val = Ksmallest(root->left,k);
        if(k ==0) return val;
        if(--k==0) return root->val;
        return Ksmallest(root->right,k);
    }
};
