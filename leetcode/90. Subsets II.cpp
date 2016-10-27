class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> total ={{}};
        vector<int> instance;
        // total.push_back(vector<int>());
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); ){
            int count = 0;
            while (count+i<nums.size() && nums[count+i] == nums[i]){
                count++;
            } 
            int sum = total.size();
            for (int j = 0; j < sum; j++){
                instance = total[j];
                for(int k = 0; k < count; k++){
                    instance.push_back(nums[i]);
                    total.push_back(instance);
                }
            }
            
            i = i + count;
        }
        return total;
        
        
    }
};
