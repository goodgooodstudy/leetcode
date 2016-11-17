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

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum+=i;
        if(sum%2 != 0) return false;
        int target = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));
        for(int end = 0; end < nums.size(); end++){
            for(int j = 0; j <= target; j++){
        dp[end][j] = end == 0? j == 0: dp[end-1][j] ||( j-nums[end] >= 0 && dp[end-1][j-nums[end]]);
            }
        }
        return dp[nums.size()-1][target];
        // unordered_set<int> sums;
        // sums.insert(0);
        // for(auto i : nums){
        //     vector<int> tmp;
        //     for(int j : sums){
        //         if(i + j == target) return true;
        //         tmp.push_back(i+j);
        //     }
        //     for(int i : tmp){
        //         sums.insert(i);
        //     }
        // }
        // return false;

    }

};

class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> visited;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum+=i;
        if(sum%2 != 0) return false;
        int target = sum/2;
        // vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));
        // for(int end = 0; end < nums.size(); end++){
        //     for(int j = 0; j <= target; j++){
        // dp[end][j] = end == 0? j == 0: dp[end-1][j] ||( j-nums[end] >= 0 && dp[end-1][j-nums[end]]);
        //     }
        // }
        // return dp[nums.size()-1][target];
        return hasSum(nums, nums.size()-1, target);

    }
    bool hasSum(vector<int>& nums, int end, int target){
        if(end < 0 || target <= 0) return target == 0;
        if(visited.count(end) == 0|| visited[end].count(target) == 0){
            visited[end][target] = hasSum(nums, end-1, target- nums[end]) || hasSum(nums, end-1, target);//order matters a lot
        }
        return visited[end][target];
    }
};
