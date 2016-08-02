class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <=1) return n;
        vector<int> length(n,1);
        int mlength = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    length[i] = max(length[i],length[j]+1);
                }
            }
            mlength = max(length[i],mlength);
        }
        return mlength;
        
    }
};

/*nlogn*/
class Solution {
public:

    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> ends;
        for(int i = 0; i < nums.size(); i++){
            int l = 0, r = ends.size()-1;
            if(ends.size()==0 || nums[i] > ends.back()){
                ends.push_back(nums[i]);
                continue;
            }
            while(l < r){
                int mid = (l+r)/2;
                if(nums[i] <= ends[mid]) r = mid;
                else l = mid+1;
            }
            ends[r] = nums[i];
        }
        return ends.size(); //ends are not the exact subsequence
        
    }
};
