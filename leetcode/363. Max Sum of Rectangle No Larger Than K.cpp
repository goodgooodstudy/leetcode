class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size(),res=INT_MIN;
        for(int i = 0; i<col; i++){
            vector<int> sums(row,0);
            for(int j =i; j < col; j++){
                for(int k =0; k<row; k++){
                    sums[k]+=matrix[k][j];
                }
                
                //find cur no larger than k
                set<int> curset;
                curset.insert(0);
                int curMax=INT_MIN,curSum=0;
                for(int sum:sums){
                    curSum+=sum;
                    set<int>::iterator it = curset.lower_bound(curSum-k);
                    if(it!=curset.end()) curMax = max(curMax,curSum-*it);
                    curset.insert(curSum);
                }
                res = max(res,curMax);
            }
        }
        return res;
    }
};
