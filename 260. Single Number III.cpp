class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2,0);
        if(nums.size() <2) return  res;
        int axorb = nums[0];
        for(int i = 1; i < nums.size();i++) axorb^=nums[i];
        int lastdigit = (axorb&(axorb-1))^axorb;
        for(auto n : nums){
            if(n & lastdigit) res[0] ^= n;
            else{
                res[1] ^= n;
            }
        }
        return res;
        
    }
};
