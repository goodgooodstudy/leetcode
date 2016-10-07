class Solution {
public:
    bool isValidSerialization(string preorder) {
        string node;
        stringstream ss(preorder);
        vector<string> stack;
        while (getline(ss, node, ',')) {
            stack.push_back(node);
            cout  << node <<endl;
            
            while (stack.size() >= 3) {
                int size = stack.size();
                if(stack[size-1] == "#" && stack[size-2] == "#" && stack[size-3] != "#"){
                    // stack.pop_back();
                    // stack.pop_back();
                    // stack.pop_back();
                    stack.erase(stack.end()-3,stack.end());
                    stack.push_back("#");
                }
                else break;
            }
        }
        if (stack.size() == 1 && stack[0] =="#") {
            return true;
        }
        else return false;
        
    }
};

// hard to come up with 
class Solution {
public:
    bool isValidSerialization(string preorder) {
        string node;
        stringstream ss(preorder);
        int diff = 1;
        while (getline(ss, node, ',')) {
            if(--diff <0) return false;
            if(node != "#") diff+=2;
            
        }
        return diff == 0;
    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string cur;
        int slot = 1;
        while(getline(ss, cur, ',')){
            if(slot == 0) return false;
            if(cur == "#"){
                slot -= 1;
            }
            else {
                slot += 1;
            }
        }
        return slot == 0;
    }
};
