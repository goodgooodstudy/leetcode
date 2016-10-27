class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cbns(target+1,0);
        cbns[0] = 0;
        for(int i = 1; i <= target; i++){
            for(auto num: nums){
                if(num == i) cbns[i] ++;
                else if(num < i){
                   cbns[i] += cbns[i-num]; 
                } 

            }
        }
        return cbns[target];
    }
};
