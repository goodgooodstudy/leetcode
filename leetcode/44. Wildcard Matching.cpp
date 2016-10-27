class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.size(),pn = p.size();
        int si =0, pi = 0;
        int asterisk = -1, match;
        while(si < sn){
            if(pi<pn && (s[si] == p[pi] || p[pi] =='?')){
                si++;
                pi++;
            }
            else if(pi < pn && (p[pi]=='*')){
                asterisk = pi++;
                match = si;
            }
            else if(asterisk>=0){
                si = ++match;
                pi = asterisk+1;
            }
            else{
                return false;
            }
            
        }
        while(pi <pn &&p[pi] == '*') pi++;
        return pi == pn;
        
    }
};

class Solution {
private:
    
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        cout << n1 << " "<<n2<<endl;
        vector<bool> dp(n2+1,false);

        dp[0] = true;
        for(int j = 1; j <= n2; j++){
            if(p[j-1] == '*') dp[j] = dp[j-1];
        }
        for(int i = 1; i <= n1; i++){
            vector<bool> ori = dp;
            dp[0] = false;
            for(int j = 1; j <= n2; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[j] = ori[j-1];
                }
                else if(p[j-1] == '*'){
                    dp[j] = dp[j-1] || ori[j];
                }
                else dp[j] = false;
            }
            
        }
        return dp[n2];

    }
};
