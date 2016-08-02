class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() <3) return false;
        int a1 = 0x7fffffff, a2 = 0x7fffffff;
        for(int num:nums){
            if(num <= a1) a1 = num;
            else if(num <= a2) a2 = num;
            else return true;
        }
        return false;
        
    }
};
