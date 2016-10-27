class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> rets;
        vector<int> solution;
        vector<bool> chosen(nums.size(),false);

        sort(nums.begin(),nums.end());
        getPermuteUnique(nums, rets, solution, chosen);
        return rets;
    }
    void getPermuteUnique(vector<int>& nums, vector<vector<int>>& rets, vector<int>& solution, vector<bool>& chosen ){
        if(solution.size() == nums.size()) rets.push_back(solution);
        if(solution.size() > nums.size()) return;
        
        for(int i=0; i<nums.size(); i++){
            if( i>0 && nums[i] == nums[i-1] && chosen[i-1]) continue; //chosen[i-1] cannot think of it....
            if(!chosen[i]){
                solution.push_back(nums[i]);
                chosen[i] = true;
                getPermuteUnique(nums, rets, solution, chosen);
                solution.pop_back();
                chosen[i] = false;
            }
        }
    }
};
