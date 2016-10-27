class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int y = matrix[0].size()-1,x=0;
        for(; x <matrix.size(); x++){
            while(y>=0 && matrix[x][y] >target) y--;
            if(y>=0 && matrix[x][y] == target) return true;
        }
        
        return false;
    }
};
