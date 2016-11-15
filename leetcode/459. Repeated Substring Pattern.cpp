class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        vector<int> dp(n, 0);
        int i = 0, j= 1;
        while(j < n){
            if(str[i] == str[j]){
                dp[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i == 0){
                    dp[j] = 0;
                    j++;
                }
                else{
                    i = dp[i-1];
                }
            }
        }
        cout << dp[n-1]%(n-dp[n-1])<<endl;
        return dp[n-1] && (dp[n-1]%(n-dp[n-1])==0);
    }
};
