/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL) res = res+"n,";
            else{
                res = res+to_string(cur->val)+",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
        
    }
    vector<string> split(string s){
        stringstream ss(s);
        vector<string> res;
        string tmp;
        while(getline(ss,tmp,',')) res.push_back(tmp);
        return res;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        vector<string> dd = split(data);
        TreeNode* root = new TreeNode(stoi(dd[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i < dd.size()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur != NULL){
                if(dd[i]!="n"){
                    TreeNode* left = new TreeNode(stoi(dd[i]));
                    cur->left = left;
                }
                else{
                    cur->left=NULL;
                }
                i++;
                if(dd[i]!="n"){
                    TreeNode* right = new TreeNode(stoi(dd[i]));
                    cur->right = right;
                }
                else{
                    cur->right=NULL;
                }
                i++;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return root;

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
