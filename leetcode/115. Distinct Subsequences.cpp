class Solution {
public:
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int t1 = t.size();
        vector<vector<int>> cnt(s1+1, vector<int>(t1+1,0));
        for(int i = 0; i < s1+1; i++)   cnt[i][0]=1;
        for(int i = 1; i < s1+1; i++){
            for(int j = 1; j < t1+1; j++){
                if(s[i-1] == t[j-1]){
                    cnt[i][j] = cnt[i-1][j-1] + cnt[i-1][j];
                }
                else{
                    cnt[i][j] = cnt[i-1][j];
                }
            }
        }
        return cnt[s1][t1];
        
    }
};


class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(m==0 && n==0) return 1;
        if(m==0||n==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(s[0] == t[0])dp[0][0]=1;
        for(int i = 1; i < m; i++){
            if(s[i] == t[0]) dp[i][0] = dp[i-1][0]+1;
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};
