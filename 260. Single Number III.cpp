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

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> rst(2,0);
        int axorb = 0;
        for(auto n:nums) axorb^=n;
        int lastdigit = axorb&(~(axorb-1));
        for(auto n : nums){
            if(n&lastdigit){
                rst[0] ^= n;
            }
            else{
                rst[1] ^= n;
            }
        }
        return rst;
    }
};
