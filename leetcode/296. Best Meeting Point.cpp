class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> x;
        vector<int> y;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    x.push_back(i);
                    y.push_back(j);
                } 
            }
        }
        int median_x = x[x.size()/2];
        nth_element(y.begin(), y.begin()+y.size()/2, y.end());
        int median_y = y[y.size()/2];
        int total = 0;
        for(auto tmp : x) total += abs(median_x-tmp);
        for(auto tmp : y) total += abs(median_y-tmp);
        return total;
        
    }
};
