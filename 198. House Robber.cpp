class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        vector<int> profit(nums.size(),0);
        profit[0] = nums[0];
        profit[1] = max(profit[0],nums[1]);
        for(int i = 2; i < nums.size();i++){
            profit[i] = max(profit[i-2]+nums[i], profit[i-1]);
        }
        return profit[nums.size()-1];
    }
};
