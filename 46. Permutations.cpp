class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rets;
        vector<int> solution;
        vector<bool> chosen(nums.size(), false);
        getPermution(rets, solution, nums, chosen);
        return rets;
        
    }
    void getPermution(vector<vector<int>>& rets, vector<int>& solution, vector<int>& nums, vector<bool>& chosen){
        if(solution.size() == nums.size())
            rets.push_back(solution);
        if(solution.size() > nums.size()) return;
        
        for(int i =0; i <nums.size();i++){
            if(!chosen[i]){
                solution.push_back(nums[i]);
                chosen[i] = true;
                getPermution(rets, solution, nums, chosen);
                solution.pop_back();
                chosen[i] = false;
            }
            
        }
        
    }
};
