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
