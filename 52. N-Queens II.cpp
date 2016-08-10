class Solution {
    private:
    int n;

public:
    int totalNQueens(int n) {
        this->n = n;
        vector<vector<string>> res;
        vector<string> ans (n,string(n,'.'));
        solNQueensHelper(res,ans,0);
        return res.size();
    }

    void solNQueensHelper(vector<vector<string>>& res,vector<string>& ans,int row){
        if(row == n) res.push_back(ans);
        for(int i = 0; i < n; i++){
            if(isValid(ans,row,i)){
                ans[row][i] = 'Q';
                solNQueensHelper(res,ans,row+1);
                ans[row][i] = '.';
            }
        }
        
    }
    bool isValid(vector<string>& ans,int row,int col){
        for(int i = 0; i!=row; i++){
            if(ans[i][col] == 'Q')return false;
        }
        //check 135 degrees
        for(int r = row-1, c = col-1; r>=0 &&c >=0; r--,c--){
            if(ans[r][c] == 'Q') return false;
        }
        for(int r = row-1, c = col+1; r>=0 && c < n; r--,c++){
            if(ans[r][c] == 'Q') return false;
        }
        return true;
        
    }
};
