class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n,false));
        for(int i = n-1; i>=0; i--){
            for(int j = i; j < n; j++){
                isPal[i][j] = s[i] == s[j] && (j-i <=2 || isPal[i+1][j-1]);
            }
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0] = -1;
        for(int i = 0; i < n; i++){
            for(int j = i; j>=0; j--){
                if(isPal[j][i]){
                    dp[i+1] = min(dp[i+1],dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};
