class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)return 0;
        int maxNum = nums[0], minNum = nums[0];
        for(auto n : nums){
            maxNum = max(maxNum,n);
            minNum = min(minNum,n);
        }

        int len = (maxNum-minNum)/nums.size()+1;
        vector<vector<int>> buckets((maxNum-minNum)/len+1); // easy wrong
        for(int i = 0; i<nums.size();i++){
            int idx = (nums[i]-minNum)/len;
            if(buckets[idx].size()<2){
                buckets[idx].push_back(nums[i]);
                buckets[idx].push_back(nums[i]);
            }
            else{
                buckets[idx][0] = min(buckets[idx][0],nums[i]);
                buckets[idx][1] = max(buckets[idx][1],nums[i]);
            }
            
        }
        int maxGap = len-1;
        int prev = 0;
        for(int i = 1; i<buckets.size(); i++){ // very concise to do 
            if(buckets[i].empty())continue;
            maxGap = max(buckets[i][0]-buckets[prev][1],maxGap);
            prev = i;
        }
        return maxGap;
        
    }
};
