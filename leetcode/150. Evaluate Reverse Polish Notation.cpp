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
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;
        unordered_set<string> op ={"+","-","*","/"};
        for(string token : tokens){
            if(op.count(token)){
                int n2 = sk.top(); ///pay attention to / since n2 is divisor
                sk.pop();
                int n1 = sk.top();
                sk.pop();
                int res = compute(n1, n2, token);
                sk.push(res);
            }
            else{
                cout << stoi(token)<<endl;
                sk.push(stoi(token));
            }
        }
        return sk.top();
        
    }
    int compute(int n1, int n2, string op){
        if(op == "+"){
            return n1 + n2;
        }
        else if(op == "-"){
            return n1 - n2;
        }
        else if(op == "*"){
            return n1*n2;
        }
        else{
            return n1 / n2;
        }
    }
};
