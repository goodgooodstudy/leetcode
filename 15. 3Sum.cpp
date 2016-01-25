class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());
        if(nums.size()<3 || nums[0]>0 || nums[-1] <0) return results;
        int total;
        
        for(int i = 0; i<nums.size()-2 && nums[i] <= 0;i++){
            total = 0-nums[i];
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size();j++){
                int k = nums.size()-1;
                while(j<k){
                    if(nums[j] + nums[k]< total){
                        j++;
                    }
                    else if(nums[j] + nums[k] > total){
                        k--;
                    }
                    else{
                        while(j+1<k &&nums[j] == nums[j+1]) j++;
                        while(k-1 >j &&nums[k] == nums[k-1]) k--;
                        vector<int> tmp = {nums[i],nums[j],nums[k]};
                        results.push_back(tmp);
                        j++;
                        k--;
                        
                    }
                    
                }
            }
        }
        return results;
    }
};
