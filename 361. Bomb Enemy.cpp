class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        int rowSum = 0, colSum[n]={0};
        int mx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!j || grid[i][j-1] == 'W'){
                    rowSum = 0;
                    for(int k = j; k<n && grid[i][k] !='W'; k++){
                        rowSum += grid[i][k] == 'E';
                    }
                }
                if(!i || grid[i-1][j] == 'W'){
                    colSum[j] = 0;
                    for(int k = i; k < m && grid[k][j] != 'W'; k++){
                        colSum[j] += grid[k][j] == 'E';
                    }
                }
                
                if(grid[i][j] == '0'){
                    mx = max(mx, colSum[j] + rowSum);
                }
            }
        }
        return mx;
        
    }
};
