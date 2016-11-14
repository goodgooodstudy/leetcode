class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0] = -1;
        int total = 0;
        int mx = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            if(mp.count(total-k)){

                mx = max(mx, i-mp[total-k]);
            }
            if(!mp.count(total)){
                mp[total] = i;
            }
            // cout << mp[total]<<endl;
            
        }
        return mx;
    }
};
