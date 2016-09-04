class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.empty()){
            if(lower == upper) res.push_back(to_string(lower));
            else res.push_back(to_string(lower)+"->"+to_string(upper));
            return res;
        }
        nums.insert(nums.begin(),lower-1);
        nums.insert(nums.end(),upper+1);

        for(int i = 1; i < nums.size();i++){

            if(nums[i]<=nums[i-1]+1){
                continue;
            }
            else if(nums[i] - nums[i-1] == 2){
                res.push_back(to_string(nums[i]-1));
            }
            else{
                res.push_back(to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1));
            }
            
        }
        return res;
        
    }
};
