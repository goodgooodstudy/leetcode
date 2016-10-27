class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX,n=nums.size(),left=0,right=0,sum=0;
        while(right < n){
            do sum+=nums[right++];
            while(sum<s&&right<n);
            cout << right<<endl;
            while(left<n && sum-nums[left]>=s)sum-=nums[left++];
            if(sum>=s)minLen = min(minLen,right-left);
        }
        return minLen == INT_MAX?0:minLen;
        
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sum(nums.size(),0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum[i] = sum[i-1]+nums[i];
        }
        int minLen = INT_MAX;
        for(int i = 0; i < nums.size();i++){
            if(sum[i] >=s){
                vector<int>::iterator it = upper_bound(sum.begin(),sum.begin()+i+1,sum[i]-s);
                if(it!=sum.end())minLen = min(minLen, i-int(it-sum.begin())+1);
            }
        }
        return minLen == INT_MAX?0:minLen;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> sums(nums.size()+1,0);
        calculate(sums, nums);
        int mx = INT_MAX;
        for(int i = 1; i <= nums.size(); i++){
            if(sums[i] >= s){
                 int p = upper_bound(sums,0,i, sums[i]-s);
                if(p!=-1) mx = min(mx, i-p+1);
            }
           
            
        }
        return mx == INT_MAX?0:mx;
    }
    void calculate(vector<int>& sum, vector<int>& nums){
        int s = nums[0];
        for(int i = 1; i <= nums.size(); i++){
            sum[i] = nums[i-1] + sum[i-1];
        }
    }
    //  int upper_bound(vector<int>& sums, int left, int right, int target) {
    //     int l = left, r = right;
    //     while (l < r) {
    //         int m = l + ((r - l) >> 1);
    //         if (sums[m] <= target) l = m + 1;
    //         else r = m;
    //     }
    //     return sums[r] > target ? r : -1;
    // }
    int upper_bound(vector<int>& sums, int l, int r, int target){
        while(l < r){
            int mid = l + (r-l)/2;
            if(target >= sums[mid]){
                l = mid+1;
            }
            else r = mid;
            
        }
        if(sums[r] > target) return r;
        return -1;
    }
};
