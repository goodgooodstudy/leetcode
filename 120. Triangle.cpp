class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if(rows ==0) return 0;
        vector<int> minV = triangle[rows-1];
        for(int i = rows-2; i >=0 ; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                minV[j] = min(minV[j],minV[j+1])+triangle[i][j];
            }
        }
        return minV[0];

    }
 
};
