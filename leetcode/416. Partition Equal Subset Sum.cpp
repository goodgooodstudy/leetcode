class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto n : nums) total+=n;
        if(total%2 !=0) return false;
        total = total/2;
        sort(nums.begin(), nums.end());
        vector<bool> dp(total+1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++){
            for(int j = total; j >=nums[i]; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[total];
        
    }
   
};
