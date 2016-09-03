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
