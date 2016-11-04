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
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        int mx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') dp[i] = 0;
            else{
                if(i-1 < 0) continue;
                if(s[i-1] == '(') dp[i] = dp[i-2]+2;
                else{
                    int j = i-1 - dp[i-1]+1;
                    if(j-1>=0 && s[j-1] == '('){
                        dp[i] = dp[i-1]+2;
                        if(j-2 >=0) dp[i]+=dp[j-2];
                    }
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
        
    }
};
