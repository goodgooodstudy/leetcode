class Solution {
// | 1 | 2 | 3 |
// | 4 | 5 | 6 |
// | 7 | 8 | 9 |
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10,0));
        skip[1][3] = 2, skip[3][1] = 2;
        skip[1][7] = 4, skip[7][1] = 4;
        skip[3][9] = 6, skip[9][3] = 6;
        skip[7][9] = 8, skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[6][4]= skip[4][6] = skip[2][8] = skip[8][2] = 5;
        int total = 0;
        vector<bool> visited(10,false);
        for(int i = m; i <= n; i++){
            total+= 4* dfs(1, visited, skip, i-1 ); //1,3,7,9
            total+= 4* dfs(2, visited, skip, i-1 ); //2,4,6,8
            total+= dfs(5, visited, skip, i-1 ); //5

        }
        return total;
        
    }
    int dfs(int start, vector<bool> visited, vector<vector<int>>& skip, int target){
        if(target == 0){
            return 1;
        }
        if(target < 0) return 0;
        int total = 0;
        visited[start] = true;
        for(int i = 1; i <= 9; i++){
            if(!visited[i] && (skip[i][start] == 0 || visited[skip[i][start]])){
                total+=dfs(i, visited, skip, target-1);
            }
        }
        visited[start] = false;
        return total;
    }
};
