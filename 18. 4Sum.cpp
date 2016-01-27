class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size() < 4) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size()-3; i++){
            if(i-1>=0 && nums[i] == nums[i-1])continue;
            for(int j = i+1; j<nums.size()-2; j++){
                if(j-1 >= i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, l = nums.size()-1;
                while(k<l){

                    int all = nums[i] + nums[j] +nums[l] + nums[k];
                    if(all == target){

                        while(k+1 < l && nums[k] == nums[k+1]) k++;
                        while(l-1 > k && nums[l-1] == nums[l]) l--;
                        ret.push_back({nums[i] , nums[j] ,nums[k] , nums[l]});
                        k++;
                        l--;

                    } 
                    else if(all < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ret;
        
    }
};
