class Solution {
public:
    int calculate(string s) {
        stack<int>nums,ops;
        int sign = 1;
        int num = 0;
        int rst = 0;
        
        for(char c: s){
            if(isdigit(c)){
                num = num*10 + c-'0';
            }
            else{
                rst += sign*num;
                num = 0;
                if(c == '+') sign = 1;
                if(c == '-')sign = -1;
                if(c == '('){
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if(c == ')'){
                    rst = nums.top()+ops.top()*rst;
                    nums.pop();
                    ops.pop();
                }
                
            }
        }
        rst += sign*num;
        return rst;
    }
    
};

class Solution {
public:
    int calculate(string s) {
        int total = 0;
        int sign = 1;
        int i = 0;
        for(int i = 0;  i < s.size(); i++){
            if(s[i] == ' '){
                continue;
            }
            else if(s[i] == '('){
                int right = findright(s, i);
                total = total + sign*calculate(s.substr(i+1,right-i-1));
                i = right;
            }
            else if(s[i] == '+' || s[i] == '-'){
                sign = s[i] == '+' ? 1 : -1;
            }
            else{
                int n = s[i]-'0';
                while(i+1 < s.size() && isalnum(s[i+1])){
                    n = n*10 + s[i+1]-'0';
                    i++;
                }
                total = total + sign*n;
            }
            
        }
        
        return total;
    }
    int findright(string s, int pos){
        int left = 0;
        for(int i = pos; i < s.size(); i++){
            if(s[i] == '(') left++;
            if(s[i] == ')') left--;
            if(left == 0) return i;
        }
        return s.size()-1;
    }
};
