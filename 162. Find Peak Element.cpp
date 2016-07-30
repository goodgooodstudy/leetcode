class Solution {
public:
    // int findPeakElement(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 1) return 0;
    //     if(nums[n-1] > nums[n-2]) return n-1;
    //     for(int i =1; i<nums.size()-1; i++){
    //         if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
    //     }
    //     return 0;
        
    // }
    // int findPeakElement(vector<int>& nums) {
    //     int left = 0, right = nums.size()-1;
    //     while(left < right){
    //         int mid = (left+right)/2;
    //         if(nums[mid] < nums[mid+1]) left = mid+1;
    //         else right = mid;
    //     }
    //     return left;
        
    // }
    int findPeakElement(vector<int>& nums){
        int i = 1;
        for(; i <nums.size();i++){
            if(nums[i-1]>nums[i]) return i-1;
        }
        return i-1;
    }
};
