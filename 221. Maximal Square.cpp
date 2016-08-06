class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        int mSquare = 0;
        for(int i = 0; i < row; i++){
            dp[i][0]= (matrix[i][0]=='0')?0:1;
            mSquare= max(mSquare,dp[i][0]);
        }
        for(int j = 0; j < col; j++){
            dp[0][j] = matrix[0][j]=='0'?0:1;
            mSquare = max(mSquare,dp[0][j]);
        }
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j]=='1'){
                    if(dp[i-1][j]&& dp[i-1][j-1] && dp[i][j-1]){
                        dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;

                    }
                    else{
                        dp[i][j] = 1;

                    }
                    mSquare = max(mSquare,dp[i][j]);

                }
            }
        }
        return mSquare*mSquare;
        
    }
};
