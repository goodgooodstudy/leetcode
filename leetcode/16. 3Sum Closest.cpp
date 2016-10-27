class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        if(size<3) return res;
        res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i<size;i++){
            int j = i+1, k = size-1;
            while(j<k){
                int tmp = nums[i] + nums[j]+nums[k];
                if(tmp == target) return target;
                else if(tmp < target){
                    j++;
                }
                else {
                    k--;
                }
                if(abs(target -tmp) < abs(target-res)){
                    res = tmp;
                }
                
            }
            
            
        }
        return res;
        
        
    }
};
