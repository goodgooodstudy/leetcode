class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        int m = rooms.size();
        if(m == 0)return;
        int n = rooms[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0){
                    q.emplace(i,j);
                }
            }
        }

        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            int row = cur.first, col = cur.second;
            if(row > 0 && rooms[row-1][col] == INT_MAX){
                rooms[row-1][col] = rooms[row][col] + 1;
                q.emplace(row-1, col);
            }
            if(row < m-1 && rooms[row+1][col] == INT_MAX){
                rooms[row+1][col] = rooms[row][col] + 1;
                q.emplace(row+1,col);
            }
            if(col > 0 && rooms[row][col-1] == INT_MAX){
                rooms[row][col-1] = rooms[row][col] + 1;
                q.emplace(row, col-1);
            }
            if(col < n-1 && rooms[row][col+1] == INT_MAX ){
                rooms[row][col+1] = rooms[row][col] + 1;
                q.emplace(row, col+1);
            }
        }
        return;
        
    }
};
