class Solution {
public:
    void solve(vector<vector<char>>& board) {
       int row = board.size();
       if(row == 0) return;
       int col = board[0].size();
       for(int j =0; j< col; j++){
           check(board,0,j);
           if(row>1)check(board,row-1,j);
       }
       for(int i = 1; i < row-1; i++){
           check(board,i,0);
           if(col>1)check(board,i,col-1);
       }
       for(int i = 0; i<row; i++){
           for(int j =0; j <col; j++){
               if(board[i][j] == 'O') board[i][j] = 'X';
               if(board[i][j] == '1') board[i][j] = 'O';
           }
       }
    }
    void check(vector<vector<char>>& board, int i, int j){
        int row = board.size();
        int col = board[0].size();
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            if(i-1>0) check(board,i-1,j);
            if(i+1<row)check(board,i+1,j);
            if(j-1>0)check(board,i,j-1);
            if(j+1<col)check(board,i,j+1);
        }
    }
};



class Solution {
private:
    int m, n;
    vector<pair<int, int>> go = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0) return;
        n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') dfs(board, 0,j);
            if(board[m-1][j] == 'O')dfs(board, m-1, j);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '1') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
                else continue;
            }
        }
        
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(board[i][j]!='O') return;
        board[i][j] = '1';
        queue<pair<int, int>> q;
        q.emplace(i,j);
        while(!q.empty()){
            auto cur = q.front();
            // board[cur.first][cur.second] = '1';
            q.pop();
            if(cur.first - 1 >=0 && board[cur.first-1][cur.second]=='O'){
                q.emplace(cur.first-1, cur.second);
                board[cur.first-1][cur.second]='1';
            }
            if(cur.first+1 < m && board[cur.first+1][cur.second] == 'O'){
                board[cur.first+1][cur.second]='1';

                q.emplace(cur.first+1, cur.second);
            }
            if(cur.second + 1 < n && board[cur.first][cur.second+1] == 'O'){
                board[cur.first][cur.second+1]='1';

                q.emplace(cur.first, cur.second+1);
            }
            if(cur.second-1 >=0 && board[cur.first][cur.second-1]=='O'){
                board[cur.first][cur.second-1]='1';

                q.emplace(cur.first, cur.second-1);
            }
        }
    }
    // void dfs(vector<vector<char>>& board, int i, int j){
    //     int row = board.size();
    //     int col = board[0].size();
    //     if(board[i][j] == 'O'){
    //         board[i][j] = '1';
    //         if(i-1>0) dfs(board,i-1,j);
    //         if(i+1<row)dfs(board,i+1,j);
    //         if(j-1>0)dfs(board,i,j-1);
    //         if(j+1<col)dfs(board,i,j+1);
    //     }
    // }
    // void dfs(vector<vector<char>>& board, int i, int j){
    //     if(i<0 || i>=m||j <0 || j>= n||board[i][j]!='O' ) return;
    //     board[i][j] = '#';
    //     for(int k = 0; k < 4; k++) dfs(board, i+go[k].first,j+go[k].second);
    // }
};
