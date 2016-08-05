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
