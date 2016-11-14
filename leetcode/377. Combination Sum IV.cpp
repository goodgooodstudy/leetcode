class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //follow up limit the length
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i =1; i <= target; i++){
            for(auto n : nums){
                if(i < n) continue;
                else dp[i] += dp[i-n];
            }
        }
        return dp[target];
    }
    
};
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cbns(target+1,0);
        cbns[0] = 0;
        for(int i = 1; i <= target; i++){
            for(auto num: nums){
                if(num == i) cbns[i] ++;
                else if(num < i){
                   cbns[i] += cbns[i-num]; 
                } 

            }
        }
        return cbns[target];
    }
};
