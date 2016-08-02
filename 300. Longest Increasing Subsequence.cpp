class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <=1) return n;
        vector<int> length(n,1);
        int mlength = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    length[i] = max(length[i],length[j]+1);
                }
            }
            mlength = max(length[i],mlength);
        }
        return mlength;
        
    }
};
