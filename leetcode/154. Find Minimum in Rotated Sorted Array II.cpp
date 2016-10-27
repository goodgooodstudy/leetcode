class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0; 
        int end = nums.size()-1;
        while(begin < end){
            int mid = (begin+end)/2;
            if(nums[mid] < nums[end]){
                end = mid;
            }
            else if (nums[mid] > nums[end]){
                begin = mid +1;
            }
            else{
                end --;
            }
        }
        
        return nums[begin];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            if(nums[l] < nums[r]) return nums[l];
            int mid = l + (r-l)/2;
            if(nums[l] < nums[mid]){
                l = mid+1;
            }
            else if(nums[l] > nums[mid]){
                r = mid;
            }
            else{
                l++;
            }
        }
        return nums[l];
        
    }
};
