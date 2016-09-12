class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        
        for(auto inc : updates){
            res[inc[0]] += inc[2];
            if(inc[1] + 1  < length){
                res[inc[1]+1] -= inc[2]; 
            }
        }
        int sum = 0;
        for(int i = 0; i < length; i++){
            sum += res[i];
            res[i] = sum;
        }
        return res;
        
    }
};
