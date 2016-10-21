class Solution {
private:
    int m, n;
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> rst;
        m = matrix.size();
        if(m==0) return rst;
        n = matrix[0].size();
        vector<vector<bool>>Pacific(m, vector<bool>(n, false));
        vector<vector<bool>>Atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            dfs(matrix, Pacific, INT_MIN, i, 0);
            dfs(matrix, Atlantic, INT_MIN, i, n-1);
        }
        for(int j = 0; j < n; j++){
            dfs(matrix, Pacific, INT_MIN, 0, j);
            dfs(matrix, Atlantic, INT_MIN, m-1, j);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(Pacific[i][j] && Atlantic[i][j]){
                    rst.emplace_back(i,j);
                }
            }
        }
        return rst;
        
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int previous, int i, int j){
        if(visited[i][j] || matrix[i][j] < previous) return;
        visited[i][j] = true;
        if(i+1 < m) dfs(matrix, visited, matrix[i][j], i+1, j);
        if(i-1 >=0) dfs(matrix, visited, matrix[i][j], i-1, j);
        if(j-1 >=0) dfs(matrix, visited, matrix[i][j], i, j-1);
        if(j+1 < n) dfs(matrix, visited, matrix[i][j], i, j+1);
    }
};
