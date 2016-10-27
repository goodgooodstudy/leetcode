class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int m = nums[0];
        int curP = nums[0];
        int curN = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int tmp = curP;
            curP = max(max(nums[i], curP*nums[i]), curN*nums[i]);
            curN = min(min(nums[i], curN*nums[i]), tmp*nums[i]);
            m = max(curP, m);
        }
        return m;
       
        
    }
};
