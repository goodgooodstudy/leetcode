class NumMatrix {
private:vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if(m==0) return;
        int n = matrix[0].size();
        sum = vector<vector<int>>(m,vector<int>(n,0));
        sum[0][0] = matrix[0][0];
        for(int i = 1; i < m; i++) sum[i][0]= sum[i-1][0]+matrix[i][0];
        for(int j = 1; j < n; j++) sum[0][j]=sum[0][j-1]+matrix[0][j];
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                sum[i][j] = sum[i][j-1]-sum[i-1][j-1]+sum[i-1][j]+matrix[i][j];
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1=0,s2=0,s3=0,s4=0;
        s1 = sum[row2][col2];
        s2 = row1 == 0 ? 0 : sum[row1-1][col2];
        s3 = row1 == 0||col1==0 ? 0 : sum[row1-1][col1-1];
        s4 = col1 == 0 ? 0 : sum[row2][col1-1];

        return s1-(s2-s3+s4);
        
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
