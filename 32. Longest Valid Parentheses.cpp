class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int max_len = 0;
        int last = -1; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stk.push(i);
            }
            else{
                if(stk.empty()){
                    last = i;
                }
                else{
                    stk.pop();
                    if(stk.empty()){
                        max_len = max(max_len, i-last);
                    }
                    else{
                        max_len = max(max_len, i- stk.top());
                    }

                }
            }
        }
        return max_len;
    }
};
