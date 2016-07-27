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
