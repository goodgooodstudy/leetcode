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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildBST(nums,0,nums.size()-1);
        
    }
    TreeNode* BuildBST(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BuildBST(nums,start,mid-1);
        root->right = BuildBST(nums,mid+1,end);
        return root;
    }
};
