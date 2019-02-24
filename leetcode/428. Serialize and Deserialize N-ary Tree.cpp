/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "null";
        string s ="[" + to_string(root->val);
        for(auto child : root->children){
            s += serialize(child);
        }
        s += "]";
        return s; 
        
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data=="null") return nullptr;
        int idx = 1;
        return helper(data, idx);
    }
    Node* helper(string data, int& idx){
        Node* root =nullptr;
        while(idx < data.size() && data[idx]!=']'){
            int cur = 0;
            while(idx < data.size() && data[idx] >='0' && data[idx]<='9'){
                cur = cur*10 + (data[idx]-'0');
                idx++;
            }
            if(data[idx] == 'n'){
                idx+=4;
                return root;
            } 
            root = new Node(cur);
            while(data[idx]=='['){
                idx++;
                root->children.push_back(helper(data, idx));
            }
        }
        idx++;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
