class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int cnt = 0;
        if(nums.size() < 3) return cnt;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k] < target){
                    cnt = cnt+ k-j;
                    j++;
                }else{
                    k--;
                }
                
            }
        }
        return cnt;
    }
};
