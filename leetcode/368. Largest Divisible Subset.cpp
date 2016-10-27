class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();
        if(n==0) return ans;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,0), index(n,-1);
        int m = 0,  lastidx = 0;
        for(int i = 0; i < n; i++){
            for(int j = i-1; j >=0; j--){
                if(nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    index[i] = j;
                }
            }
            if(dp[i] > m){
                m = dp[i];
                lastidx = i;
            }
            
        }
        for(int i = lastidx; i >= 0; i = index[i]){
            ans.push_back(nums[i]);
        }
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
