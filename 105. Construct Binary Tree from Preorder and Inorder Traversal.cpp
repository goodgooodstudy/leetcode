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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* tmp = BuildTreeAPI(preorder, inorder,0,preorder.size()-1,0,preorder.size()-1);
        return tmp;
        
    }
    TreeNode* BuildTreeAPI(vector<int>& preorder, vector<int>& inorder, int p_b, int p_e, int i_b, int i_e){
        if(i_b > i_e) return NULL;
        int pivot = preorder[p_b];
        int i = i_b;
        for(; i <= i_e;i++){
            if(inorder[i] == pivot) break;
        }
        int p = i-i_b+p_b;  //preorder the last element of left tree
        TreeNode* node = new TreeNode(pivot);
        node->left = BuildTreeAPI(preorder, inorder,p_b+1,p,i_b,i-1);
        node->right = BuildTreeAPI(preorder, inorder,p+1,p_e,i+1,i_e);
        return node;
    }
};
