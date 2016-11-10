class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 0; 
        int first = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != target) continue;
            else{
                if(++cnt == 1) first = i;
                else{
                    if(rand()%cnt == 0){
                        first = i;
                    }
                }
            }
        }
        return first;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
