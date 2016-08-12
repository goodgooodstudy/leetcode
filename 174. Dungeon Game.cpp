class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0) return 0;
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<vector<int>> blood(rows,vector<int>(cols,1));
        blood[rows-1][cols-1] = max(1, 1-dungeon[rows-1][cols-1]);
        for(int j = cols-2; j >=0; j--) blood[rows-1][j] = max(1, blood[rows-1][j+1]-dungeon[rows-1][j]);
        for(int i = rows-2; i >=0; i--) blood[i][cols-1] = max(1, blood[i+1][cols-1]-dungeon[i][cols-1]);
        for(int i = rows-2; i >=0; i--){
            for(int j = cols-2; j >=0; j--){
                blood[i][j] = max(1, min(blood[i+1][j], blood[i][j+1]) - dungeon[i][j]);
            }
        }
        return blood[0][0];
    }
};
