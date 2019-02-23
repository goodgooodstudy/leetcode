class Solution {
private:
    vector<vector<int>> dirs= {{0,1},{0,-1},{-1,0},{1,0}};
    int m;
    int n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        int mx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int cur_area = 0;
                    dfs(grid, i, j, cur_area);
                    mx = max(mx, cur_area);
                }
            }
        }
        return mx;
        
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int& area){
        area++;
        grid[x][y] = 0;
        for(auto dir : dirs){
            int newx = dir[0] + x;
            int newy = dir[1] + y;
            if(newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
            if(grid[newx][newy] == 0) continue;
            dfs(grid, newx, newy, area);
        }
        
    }
};
