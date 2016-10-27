class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> rets;
        vector<int> solution;
        GetCombinationSum(0, target, 0, candidates, rets, solution);
        return rets;
        
        
    }
    void GetCombinationSum(int sum, int target, int start,
    vector<int>& candidates, vector<vector<int>>& rets, vector<int>& solution){
        if(sum == target) rets.push_back(solution);
        if(sum > target) return;
        for(int i = start; i < candidates.size(); i++){
          
            solution.push_back(candidates[i]);
            GetCombinationSum(sum+candidates[i], target, i, candidates, rets, solution);
            solution.pop_back();
        }
        
        
    }
};
