class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t,res(nums.size());
        for(int i = nums.size()-1; i >=0; i--){
            int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
            res[i] = d;
            t.insert(t.begin()+d, nums[i]);
        }
        return res;
        
    }
};

class Solution {
public:
    void mergesort(vector<int>& idx, vector<int>& nums, int first, int last, vector<int>& res){
        if(first < last){
            int mid = first + (last-first)/2;
            mergesort(idx, nums, first, mid, res);
            mergesort(idx, nums, mid+1, last, res);
            int idx1 = first;
            int idx2 = mid+1;
            vector<int> tmp_idx;
            int rcnt = 0;
            while(idx1 <= mid || idx2 <= last){
                int n1 = (idx1 >= mid+1) ? INT_MAX:nums[idx[idx1]];
                int n2 = (idx2 >= last+1) ? INT_MAX: nums[idx[idx2]];
                if(n1 <= n2){
                    tmp_idx.push_back(idx[idx1]);
                    res[idx[idx1]] += rcnt;
                    idx1++;
                }
                else{
                    tmp_idx.push_back(idx[idx2]) ;
                    rcnt++;
                    idx2++;
                }
            }
            for(int i = first; i <= last; i++){
                idx[i] = tmp_idx[i-first];
            }
            
        }
      

    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n,0),res(n,0);
        iota(idx.begin(), idx.end(),0);
        
        mergesort(idx, nums, 0, (int)nums.size()-1, res);
        return res;
        
        
        
    }
};
