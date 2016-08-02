class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            for(int j = 1; j < i; j++)
                dp[i] = max(dp[i],max(j,dp[j])*max(i-j,dp[i-j]));
        }
        return dp[n];
        
    }
};

class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        if(n<=3) return n-1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i<=n; i++){
            dp[i] = max(dp[i-2]*2,dp[i-3]*3);
        }
        
        return dp[n];
        
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        int res = n%3;
        if(res == 0) return pow(3,n/3);
        else if(res == 1) return 4*pow(3,(n-4)/3);
        else  return 2* pow(3,(n-2)/3);

    }
};
