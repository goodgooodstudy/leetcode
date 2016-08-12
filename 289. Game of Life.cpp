class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int cnt = -board[i][j];
                for(int i1 = max(0,i-1); i1 < min(m,i+2); i1++){
                    for(int j1 = max(0,j-1); j1 < min(n,j+2); j1++){
                        if(board[i1][j1] & 1) cnt++;
                    }
                }
                if((cnt|board[i][j]) == 3){
                    board[i][j] |= 2;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] >>= 1;
            }
        }
    }
};
