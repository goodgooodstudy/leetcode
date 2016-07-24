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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return BuildTreeAPI(inorder, postorder, 0, inorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* BuildTreeAPI(vector<int>& inorder, vector<int>& postorder, int i_b, int i_e, int p_b, int p_e){
        if(i_b > i_e) return NULL;
        int pivot = postorder[p_e];
        int i = i_b;
        for(;i<=i_e;i++){
            if(inorder[i] == pivot) break;
        }
        int l_length = i-i_b;
        TreeNode* node = new TreeNode(pivot);
        node->left = BuildTreeAPI(inorder, postorder, i_b, i_b+l_length-1,p_b,p_b+l_length-1 );
        node->right = BuildTreeAPI(inorder, postorder, i_b+l_length+1,i_e,p_b+l_length,p_e-1 );
        return node;
        
    }
};
