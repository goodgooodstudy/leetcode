class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check[9];
        //row
        for (int row = 0; row <9; row++){
            memset(check, 0, 9*sizeof(int));
            for(int i = 0; i<9; i++){

                if(board[row][i] == '.')continue;
                if(check[board[row][i]-'1']) return false;
                check[board[row][i]-'1'] = 1;
            }
        }
        
        //col
        for(int col = 0; col < 9; col++){
            memset(check,0,9*sizeof(int));
            for(int i = 0; i < 9; i++){
              

                if(board[i][col] == '.')continue;

                if(check[board[i][col] - '1']) return false;
                check[board[i][col] -'1'] =1;
            }
        }
        
        //block
        for(int blk = 0; blk < 9; blk++){
            memset(check,0, 9 *sizeof(int));
            int j1, j2;
            for(int i = 0; i < 9; i++){
                j1= blk/3 * 3+i/3; // pay attention to the order
                j2 = blk%3 *3 + i%3;

                if(board[j1][j2] == '.')continue;
                if(check[board[j1][j2] - '1']) return false;
                check[board[j1][j2] - '1'] = 1;
            }
            
        }
        return true;
    }
};
