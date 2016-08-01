class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n,10);
        vector<int> dp(n+1,9);
        dp[0]=1;
        for(int i = 2; i < n+1; i++){
            for(int j =9; j>=11-i; j--){
                dp[i] = dp[i]*j;
            }
        }
        int ans = 0;
        for(int i =0; i <=n; i++) ans+=dp[i];
        return ans;

    }
};
