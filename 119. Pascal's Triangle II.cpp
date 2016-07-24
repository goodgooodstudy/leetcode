class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rst;
        rst.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            rst.push_back(1);
            for(int j = rst.size()-2; j>0; j--){
                rst[j] = rst[j] + rst[j-1];
            }
        }
        return rst;
        
    }
};
