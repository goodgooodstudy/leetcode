class NumMatrix {
private:
    vector<vector<int>> BIT;
    vector<vector<int>> nums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if(m==0||matrix[0].size() == 0) return;
        int n = matrix[0].size();
        this->BIT = vector<vector<int>>(m+1, vector<int>(n+1,0));
        this->nums = vector<vector<int>>(m, vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                update(i,j, matrix[i][j]);
            }
        }
        
    }

    void update(int row, int col, int val) {
        int add = val-nums[row][col];
        nums[row][col] = val;
        row++, col++;
        while(row <= nums.size()){
            int tmpy = col;
            while(tmpy <= nums[0].size()){
                BIT[row][tmpy] += add;
                tmpy = tmpy + (tmpy&(-tmpy));
            }
            row = row+ (row&(-row));
        }
    }
    int getSum(int row, int col){
        row++, col++;
        int total = 0;
        while(row > 0){
            int tmpy = col;
            while(tmpy > 0){
                total+=BIT[row][tmpy];
                tmpy = tmpy - (tmpy&(-tmpy));
            }
            row = row-(row&(-row));!!!!!()
        }
        return total;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) + getSum(row1 - 1, col1 - 1) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1);

    
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
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
