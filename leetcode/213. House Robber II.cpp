class Solution {
public:
//rob the first or rob the last
    int rob(vector<int>& nums) {
        if(nums.size() < 2) return nums.size()?nums[0]:0;
        int p1 = rob2(nums,0,nums.size()-2);
        int p2 = rob2(nums,1,nums.size()-1);
        return max(p1,p2);
        
    }
    int rob2(vector<int>& nums,int l, int r){
        int cur =0, pre =0;
        for(int i = l; i <= r; i++){
            int tmp = max(pre+nums[i],cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
    
};
