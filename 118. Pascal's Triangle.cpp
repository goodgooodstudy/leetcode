class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rst;
        if(numRows == 0) return rst;
 
        rst.push_back(vector<int>(1,1));
        for(int i = 1; i < numRows; i++){
            vector<int> cur;
            cur.push_back(rst[i-1][0]);
            for(int j = 1; j < i; j++){
                cur.push_back(rst[i-1][j] + rst[i-1][j-1]);
            }
            cur.push_back(rst[i-1][0]);

            rst.push_back(cur);
        }
        return rst;
        
    }
};
