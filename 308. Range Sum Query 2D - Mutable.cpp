class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        
        for(int i = 0; i < matrix.size(); i++){
            vector<int> cur_sum;
            int sum = 0;
            for(int j = 0; j < matrix[0].size(); j++){
                sum += matrix[i][j];
                cur_sum.push_back(sum);
            }
            sum_matrix.push_back(cur_sum);
        }
        
    }

    void update(int row, int col, int val) {
        int diff = 0;
        if(col == 0) diff = val - sum_matrix[row][col];
        else diff = val- (sum_matrix[row][col]-sum_matrix[row][col-1]);
        for(int i = col; i < sum_matrix[row].size(); i++){
            sum_matrix[row][i] += diff;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 == 0) sum+= sum_matrix[i][col2];
            else sum+= sum_matrix[i][col2]-sum_matrix[i][col1-1];
        }
        return sum;
        
    }
private:
    vector<vector<int>> sum_matrix;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
