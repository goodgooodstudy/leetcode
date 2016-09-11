class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n):diag(0),anti(0),rows(n,0),cols(n,0),N(n) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1: -1;
        rows[row] += add;
        cols[col] += add;
        if(row == col) diag += add;
        if(row == N-col-1) anti += add;
        
        if(diag == N || anti == N || rows[row] == N || cols[col] == N ) return 1;
        if(diag == -N || anti == -N || rows[row] == -N || cols[col] == -N) return 2;
        return 0;
        
    }
private:
    int diag, anti,N;
    vector<int> rows, cols;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
