class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int>path;
        backtracking(res,path,k,1,n);
        return res;
        
        
    }
    void backtracking(vector<vector<int>>& res, vector<int>& path,int k, int start,int target){
        if(target==0 && k==0) res.push_back(path);
        for(int i = start; i <= 10-k&&i<=target; i++){
            path.push_back(i);
            backtracking(res,path,k-1,i+1,target-i);
            path.pop_back();
        }
    }
};
