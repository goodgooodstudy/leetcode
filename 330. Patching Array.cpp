class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(),nums.end());
        long miss = 1; // n = 2147483647 可能会overflow
        int cnt = 0;
        int i = 0;
        while(miss <= n){
            if(i < nums.size()&&nums[i] <= miss){
                miss  = miss+nums[i];
                i++;
            }
            else{
                cnt++;
                miss = miss+miss;
            }
        }
        return cnt;
        
    }
};
