class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols+1,0);
        int mx = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++)heights[j]=(matrix[i][j]-'0')*heights[j] +(matrix[i][j]-'0') ;
            int ret = 0;
            stack<int> index;
            for(int j = 0; j < heights.size(); j++){
                while(!index.empty() && heights[j] <= heights[index.top()]){
                    int h = heights[index.top()];
                    index.pop();
                    int idx = index.empty()?-1:index.top();
                    ret = max(ret, h*(j-idx-1));
                }
                index.push(j);
            }
            mx = max(mx, ret);
            
        }
        
        return mx;
    }
};
