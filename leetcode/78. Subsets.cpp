class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = nums.size();
        int all_number = pow(2,cnt);
        vector<vector<int>> rst (all_number, vector<int>());
        
        for (int i = 0; i < all_number; i++){
            for(int j =0; j < cnt; j++ ){
                if( i>>j & 1){
                    rst[i].push_back(nums[j]);
                }
            }
        }
        return rst;
    }
};
