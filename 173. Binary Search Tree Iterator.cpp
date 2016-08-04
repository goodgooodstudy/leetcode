/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int> nums;
    int idx;
public:
    BSTIterator(TreeNode *root):idx(0) {
        inorder(root);
        
    }
    void inorder(TreeNode *root){
        if(!root) return;
        if(root->left)inorder(root->left);
        nums.push_back(root->val);
        if(root->right)inorder(root->right);
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return idx == nums.size()?false:true;
        
    }

    /** @return the next smallest number */
    int next() {
        return nums[idx++];
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
