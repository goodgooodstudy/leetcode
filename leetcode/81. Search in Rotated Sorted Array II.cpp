class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;
        while(first <= last){
            int mid = (first+last)/2;
            if(nums[mid] == target) return true;
            if(nums[first] < nums[mid]){
                if(nums[first] <= target && target < nums[mid])
                    last = mid -1;
                else
                    first = mid+1;
            }
            else if(nums[first] > nums[mid]){
                if(nums[mid] < target && target <= nums[last])
                    first = mid+1;
                else
                    last = mid-1;
            }
            else{
                first++;
            }
        }
        return false;
        
    }
};


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0,  r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[l] < nums[mid]){
                if(target >= nums[l] && target < nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
                
            }
            else if(nums[l] > nums[mid]){
                if(target >= nums[mid+1] && target <= nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            else{
                l++;
            }

        }
        return false;
    }
    
};
