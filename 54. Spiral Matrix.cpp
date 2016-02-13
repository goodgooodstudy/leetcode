class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>  results;
        if(matrix.size() == 0) return results;

        int colBegin = 0;
        int colEnd = matrix[0].size()-1; //judge whether it is null
        int rowBegin = 0;
        int rowEnd = matrix.size()-1;
        while(colBegin <= colEnd && rowBegin <= rowEnd){
            for(int i = colBegin; i <= colEnd; i++){
                if(rowBegin <=rowEnd) results.push_back(matrix[rowBegin][i]); 
            }
            rowBegin++;
            
            for(int i = rowBegin; i <= rowEnd; i++){
               if(colBegin <= colEnd)  results.push_back(matrix[i][colEnd]);
            }
            colEnd --;
            
            for(int i = colEnd; i>=colBegin; i--){
                if(rowBegin <=rowEnd) results.push_back(matrix[rowEnd][i]);// pay attention to colEnd it has been decreased....
            }
            rowEnd--;
            
            for(int i = rowEnd; i >= rowBegin; i--){
                if(colBegin <= colEnd) results.push_back(matrix[i][colBegin]);
            } 
            colBegin ++;
        }
        return results;
    }
};
