class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(),step = 0,start=0,end=0;
        // if(n==0)return 0;
        while(end < n-1){
            step++;
            int mx = end+1;
            for(int i = start; i <=end; i++){
                mx = max(i+nums[i],mx);
                if(mx >=n-1) return step;
            }
            start = end+1;
            end = mx;

        }
        
        return step;
        
    }
};
