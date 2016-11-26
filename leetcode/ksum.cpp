class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int n = A.size();
vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));
        for(int i = 0; i <= n; i++){
            dp[i][0][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                for(int t = 0; t <= target; t++){
                    dp[i][j][t] = dp[i-1][j][t];
                    if(A[i-1] <= t){
                        dp[i][j][t] += dp[i-1][j-1][t-A[i-1]];
                    }
                }
            }
        }
        return dp[n][k][target];
    }
};
