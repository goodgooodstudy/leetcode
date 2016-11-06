class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X' && (i == 0||board[i-1][j] == '.') && (j == 0|| board[i][j-1] == '.')){
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};
