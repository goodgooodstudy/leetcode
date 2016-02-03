class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        bool find = false;
        int i = 0;
        for (; i < nums.size(); i++){
            if(!find && nums[i] == target){
                find = true;
                result.push_back(i);
            }
            if(find && nums[i]!=target){
                result.push_back(i-1);
                break;
            }
        }
        
        if(find && i == nums.size()){
            result.push_back(nums.size()-1);
        }
        if(!find){
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
        
        
    }
};
