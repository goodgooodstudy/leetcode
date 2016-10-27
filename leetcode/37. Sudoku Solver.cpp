class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() < 9 || board[0].size() < 9) return;
        bool sol = solSudoku(board,0,0);
        
    }
    bool solSudoku(vector<vector<char>>& board, int row1, int col1){
        if(row1 == 9) return true;
        int row2, col2;
        row2 = row1 + (col1+1)/9;
        col2 = (col1+1)%9;
        
        if(board[row1][col1] != '.'){
            if(!isValid(board, row1,col1)) return false;
            return solSudoku(board, row2, col2);
        }
        for(int i = 1; i <10; i++){
            board[row1][col1] = '0'+i;
            if(isValid(board,row1,col1)&& solSudoku(board,row2,col2)) return true;
        }
        board[row1][col1] = '.';
        return false;

    }
    bool isValid(vector<vector<char>>& board, int row1, int col1){
        char cur = board[row1][col1];
        if(cur-'0'<1 || cur-'0'>9) return false;
        //check col and row
        for(int i = 0; i < 9; i++){
            if(board[row1][i] == cur && i != col1) return false;
            if(board[i][col1] == cur && i != row1) return false;
        }
        //check 3x3
        int row2 = row1/3*3;
        int col2 = col1/3*3;
        for(int i = row2; i <row2 + 3; i++){
            for(int j = col2; j <col2 + 3; j++){
             if( board[i][j] == cur && (i!=row1 || j!=col1) ) return false;   
            }
        }
        return true;
    }
};
