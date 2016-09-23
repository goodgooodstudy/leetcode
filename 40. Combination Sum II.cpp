class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> rets;
        vector<int> solution;
        sort(candidates.begin(),candidates.end());
        getCombSum2(0, target, 0, rets, solution, candidates);
        return rets;
        
    }
    void getCombSum2(int sum, int target, int start, vector<vector<int>>& rets, vector<int>& solution, vector<int>& candidates){
        if(sum == target) rets.push_back(solution);
        if(sum > target) return;
        
        for(int i= start; i < candidates.size(); i++ ){
            if(i>start && candidates[i] ==  candidates[i-1])continue; // i> start!!!
            solution.push_back(candidates[i]);
            getCombSum2(sum+candidates[i], target, i+1, rets, solution, candidates);
            solution.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
       vector<vector<int>> rst;
       vector<int> path;
       helper(rst, path, target, candidates, 0);
       return rst;
       
    }
    void helper( vector<vector<int>>& rst, vector<int>& path, int target, vector<int>& candidates, int start){
        if(target == 0){
            rst.push_back(path);
        }
        for(int i = start; i < candidates.size()&&candidates[i] <= target; i++){
            if(i>start && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            helper(rst, path, target-candidates[i], candidates, i+1);
            path.pop_back();
        }
    }
};
