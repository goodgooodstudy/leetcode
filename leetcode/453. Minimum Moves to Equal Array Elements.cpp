class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int mn = nums[0];
        long sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
            mn = min(mn, nums[i]);
        }
        return sum - (long)nums.size()*(long)mn;
    }
};
