class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        unordered_set<string> dict = {"+","-","*","/"};
        int res = 0;
        for(int i = 0; i< tokens.size(); i++){
            if(dict.count(tokens[i])&&s.size() >1){
                int p1 = stoi(s.top());
                s.pop();
                int p2 = stoi(s.top());
                s.pop();
                res = operate(p2,p1,tokens[i]);
                s.push(to_string(res));
            }
            else{
                s.push(tokens[i]);
            }
        }
        res = stoi(s.top());
        return res;
        
    }
    int operate(int p1, int p2, string op){
        if(op == "+") return p1+p2;
        if(op == "-") return p1-p2;
        if(op == "/") return p1/p2;
        else return p1*p2;
    } 
};
