class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int beforeMax = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++){

            beforeMax = max(nums[i],beforeMax + nums[i]);
            maxSum = max(maxSum, beforeMax);
        }
        
        return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        return maxArray(0,nums.size()-1, nums);

    }
    
    int maxArray(int left, int right, vector<int>& nums){
        if(left >  right) return INT_MIN;  //important!!!!!!!
        int mid =  (left+right)/2;
        int lmax = maxArray(left, mid-1, nums);
        int rmax = maxArray(mid+1, right, nums);
        
        int ltmp = nums[mid];
        int sum = nums[mid];
        for(int i = mid-1; i >=left; i--){
            sum = sum+nums[i];
            if( sum > ltmp){
                ltmp = sum;
            }
        }
        int rtmp = nums[mid];
        sum = nums[mid];
        for(int i = mid+1; i <= right; i++){
            sum = sum+nums[i];
            if( sum > rtmp){
                rtmp = sum;
            }
        }
        int mmax = ltmp+rtmp - nums[mid];
        
        int all = max(lmax, rmax);
        all = max(all, mmax);
        return all;
    }
};
