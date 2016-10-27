class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() >= 2){
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow!=fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
        
        
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <2) return -1;
        int low = 1;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high - low)/2;
            int cnt = 0;
            for(int n: nums){
                if(n <= mid) cnt++;
            }
            if(cnt <= mid) low = mid+1;
            else high = mid;
        }
        return low;
    }
};
