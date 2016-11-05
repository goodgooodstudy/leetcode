class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int sum = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    color(grid,i,j,sum);
                    sum++;
                }
            }
        }
        return sum;
    }
    void color(vector<vector<char>>& grid, int i, int j, int sum){
        grid[i][j] = '1'+sum+2;
        int row = grid.size();
        int col = grid[0].size();
        if(i-1>=0 && grid[i-1][j]=='1') color(grid,i-1,j,sum);
        if(i+1<row && grid[i+1][j]=='1')   color(grid,i+1,j,sum);
        if(j-1>=0 && grid[i][j-1]=='1')  color(grid,i,j-1,sum);
        if(j+1<col && grid[i][j+1]=='1') color(grid,i,j+1,sum);

    }
    
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int cnt = 1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    color(grid, i, j, cnt);
                }
            }
        }
        return cnt-1;
    }
    void color(vector<vector<char>>& grid, int i, int j, int c){
        if(grid[i][j] != '1') return;
        grid[i][j] = c+'0';
        int m = grid.size();
        int n = grid[0].size();
        if(i-1 >=0 ) color(grid, i-1, j, c);
        if(i+1 < m) color(grid, i+1, j, c);
        if(j+1 < n ) color(grid, i, j+1, c);
        if(j-1 >= 0) color(grid, i, j-1, c);
        
    }
};
