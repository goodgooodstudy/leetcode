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
        vector<int> rst;
        stack<int> s1, s2;
        inorder(root, target, true, s1);
        inorder(root, target, false, s2);
        while(k-- > 0){
            if(s1.empty()){
                rst.push_back(s2.top());
                s2.pop();
            }
            else if(s2.empty()){
                rst.push_back(s1.top());
                s1.pop();
            }
            else if(abs(s1.top() - target) < abs(s2.top()-target)){
                rst.push_back(s1.top());
                s1.pop();
            }
            else{
                rst.push_back(s2.top());
                s2.pop();
            }
        }
        return rst;
    }
    void inorder(TreeNode* root, double target, bool left, stack<int>& s){
        if(!root) return;
        inorder(left? root->left: root->right, target, left, s);
        if(left && root->val > target ||(!left && root->val <= target)) return;
        s.push(root->val);
        inorder(left? root->right: root->left, target, left, s);

    }
};
