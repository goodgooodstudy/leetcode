class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int res = INT_MAX, val = 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> sum = grid;
        vector<vector<int>> dist = grid;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    queue<pair<int,int>>q;
                    q.emplace(i,j);
                    res = INT_MAX;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(auto dir : dirs){
                            int x = cur.first + dir.first, y = cur.second + dir.second;
                            if(x >= 0 && x < m && y >=0 && y < n && grid[x][y] == val){
                                grid[x][y] = val -1;
                                dist[x][y] = dist[cur.first][cur.second] + 1;
                                sum[x][y] += dist[x][y]-1;
                                q.emplace(x,y);
                                res = min(res, sum[x][y]);
                            }
                        }
                    }
                   val--; 
                }
                
            }
        }
        return res == INT_MAX? -1:res;
    }
};
