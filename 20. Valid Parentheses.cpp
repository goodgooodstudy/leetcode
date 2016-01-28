class Solution {
public:
    bool isValid(string s) {
        vector <char> stack;
        if(s.size() == 0) return true;
        if(s[0] == '(' || s[0] == '{' || s[0] == '[') stack.push_back(s[0]);
        else return false;
        for (int i = 1; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push_back(s[i]);
                continue;
                
            }
            
            char current = stack.back();
            
            if(s[i] == ')' && current!='(') return false;
            if(s[i] == '}' && current !='{')return false;
            if(s[i] == ']' && current !='[')return false;
            stack.pop_back();

        }
        if(stack.size() == 0) return true;
        else return false;
        
        
    }
};
