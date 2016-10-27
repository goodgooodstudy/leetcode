class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        vector<int> path;
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for (int i = 0; i<n; i++){
            count += grid[0][i];
            path.push_back(count);
        }
        for(int i = 1; i<m;i++){
            path[0] = path[0] + grid[i][0];
            for(int j = 1; j < n; j++){
                path[j] = min(path[j]+grid[i][j],path[j-1]+grid[i][j]);
            }
        }
        return path[n-1];

    }
};
