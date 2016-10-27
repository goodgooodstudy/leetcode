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


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> rst;
        vector<int> path;
        backtracking(rst, path, k,n,1);
        return rst;
    }
    void backtracking(vector<vector<int>>& rst, vector<int>& path, int k, int target, int start){
        if(k==0 && target==0 ){
            rst.push_back(path);
            return;
        }
        if(k==0 || target <= 0) return;
        for(int i = start; i <= 9; i++){
            path.push_back(i);
            backtracking(rst, path, k-1, target-i,i+1);
            path.pop_back();
        }
        
    }
};
