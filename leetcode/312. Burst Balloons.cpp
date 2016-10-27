class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int left = n; left>=1; left--){

            for(int right = left; right <=n; right++){

        
                for(int k = left; k <=right; k++){
                dp[left][right] = max(dp[left][right],nums[left-1]*nums[k]*nums[right+1]+dp[left][k-1]+dp[k+1][right]);
                }

                
            }
            
        }
        return dp[1][n];
        
    }
};
