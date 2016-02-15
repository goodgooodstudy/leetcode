class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> result(n, 0);
        vector<vector<int>> results(n, result);
        int colBegin=0;
        int colEnd = n-1;
        int rowBegin = 0;
        int rowEnd = n-1;
        int count = 0;

        while(rowBegin <=rowEnd && colBegin <= colEnd){
            for(int i = colBegin; i <=colEnd; i++){
                if(rowBegin <=rowEnd )results[rowBegin][i] = ++count;
            }
            rowBegin++;
            for(int i = rowBegin; i <=rowEnd; i++){
                if(colBegin <= colEnd) results[i][colEnd] = ++count;
            }
            colEnd--;
            for(int i = colEnd; i >= colBegin; i--){
                if(rowBegin <= rowEnd) results[rowEnd][i] = ++count;
            }
            rowEnd --;
            for(int i = rowEnd; i >= rowBegin; i--){
                if(colBegin <= colEnd) results[i][colBegin] = ++count;
            }
            colBegin++;

        }
            return results;

        
    }
};
