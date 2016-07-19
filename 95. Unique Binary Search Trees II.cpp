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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(0);
        return genBST(1,n);
        
    }
    vector<TreeNode*> genBST(int min, int max){
        vector<TreeNode*> ret;
        if(min > max){
            ret.push_back(NULL);
            return ret;
        }
        for (int i = min; i <=max; i++){
            vector<TreeNode*> left = genBST(min, i-1);
            vector<TreeNode*> right = genBST(i+1,max);
            for( int j = 0; j < left.size(); j++){
                for(int k =0; k < right.size(); k++){
                    TreeNode * tmp = new TreeNode(i);
                    tmp->left = left[j];
                    tmp->right = right[k];
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};
