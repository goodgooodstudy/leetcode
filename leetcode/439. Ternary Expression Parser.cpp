class Solution {
public:
    string parseTernary(string expression) {
        stack<char> sk;
        for(int i = expression.size()-1; i >= 0; i--){
            if(!sk.empty()&& sk.top() == '?'){
                sk.pop();
                char a = sk.top();
                sk.pop();
                sk.pop();
                char b = sk.top();
                sk.pop();
                if(expression[i] == 'T') sk.push(a);
                else sk.push(b);
            }
            else{
                sk.push(expression[i]);
            }
        }
        // cout <<sk.top()<<endl;
        // string rst = ""+sk.top();
        return string(1, sk.top());
    }
};
