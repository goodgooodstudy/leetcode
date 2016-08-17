class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        multiset<long long> sums;
        long long cur = 0;
        sums.insert(0);
        for(int i = 0; i < nums.size();i++){
            cur += nums[i];
            res += distance(sums.lower_bound(cur-upper), sums.upper_bound(cur-lower));
            sums.insert(cur);
        }
        return res;
    }
};
