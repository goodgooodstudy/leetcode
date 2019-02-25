class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        dp[0][0] = grid[0][0];
        for(int k = 1; k <= m + n-2; k++){
            vector<vector<int>> cur(m, vector<int>(m, -1));
            for(int i = 0; i < m && i <= k; i++){
                if(k-i >= n) continue;
                for(int j = 0; j < m && j <= k; j++){
                    if(k-j >= n) continue;
                    if(grid[i][k-i] == -1 || grid[j][k-j] == -1) continue;
                    int cherry = dp[i][j];
                    if(j > 0) cherry = max(cherry, dp[i][j-1]);
                    if(i > 0) cherry = max(cherry, dp[i-1][j]);
                    if(i > 0 && j > 0) cherry = max(cherry, dp[i-1][j-1]);
                    if(cherry < 0) continue;
                    if(grid[i][k-i] == 1) cherry+=1;
                    if(grid[j][k-j] == 1 && j!=i) cherry+=1;
                    cur[i][j] = cherry;
                }
            }
            dp = std::move(cur); 
        }
        return max(0,dp[m-1][m-1]);
    }
};
