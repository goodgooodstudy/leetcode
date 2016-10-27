class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance = 0;
        for(int i = 0; i <=distance; i++ ){
            distance = max(i+nums[i], distance);
            if(distance >= nums.size()-1) return true;
        }
        return false;
    }
   
};
