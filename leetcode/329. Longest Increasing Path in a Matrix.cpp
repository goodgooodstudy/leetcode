class Solution {


public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int mx = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int len = dfs(matrix, i, j, m, n, visited);
                mx = max(len, mx);
            }
        }
        return mx;
        
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n,  vector<vector<int>>& visited){
        if(visited[i][j]!=0) return visited[i][j];
        int mx = 1;
        static vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for(auto dir:dirs){
            int x = i+dir[0];
            int y = j+dir[1];
            if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = dfs(matrix, x, y, m, n, visited) +1;
            mx = max(len,mx);
        }
        visited[i][j] = mx;
        return mx;
        
    }
};
