class Solution {
    int m;
    int n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(helper(board, i, j, word, 0)) return true;
            }
        }
        return false;
        
    }
    bool helper(vector<vector<char>>& board, int i, int j, string word, int idx){
        if(board[i][j]!= word[idx]) return false;
        if(idx == word.size()-1) return true; //!!! think clearly.....

        if(board[i][j] == 0) return false;
        char tmp = board[i][j];
        board[i][j] = 0;
        if(i-1>=0 &&helper(board, i-1, j, word, idx+1))return true;
        if(i+1 < m && helper(board, i+1, j, word, idx+1)) return true;;
        if(j-1>=0 && helper(board, i, j-1, word, idx+1)) return true;
        if(j+1 < n && helper(board, i, j+1, word, idx+1)) return true;
        board[i][j] = tmp;
        return false;
    }
};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        if(board[0].size() == 0) return false;
        // if(word.size() == 0) return true;
        // vector<vector<int>> map(board.size(), vector<int>(board[0].size(), 0));
        
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                    if(find(i, j, board, word, 0)) {
                        return true;
                    }

                }
        }
        
        
        return false;
    }
    
    bool find(int i, int j, vector<vector<char>>& board, string word, int index){
        if(index == word.size()) {
            return true;
        }
        if(i<0 || i >=board.size() || j <0|| j >=board[i].size()) return false;

        if(board[i][j] != word[index]) return false;
        

     
        board[i][j] = board[i][j] ^  0xFF;
  
        cout << board[i][j] <<endl;
        bool rst = find(i+1,j,board,word,index+1)||
                    find(i-1,j,board,word,index+1)||
                    find(i,j-1,board,word,index+1)||
                    find(i,j+1,board,word,index+1);

        board[i][j] ^= 0xFF;

        return rst;


    }
};
