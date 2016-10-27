class NumArray {
    vector<int>sum;
public:
    NumArray(vector<int> &nums):sum(nums.size(),0) {
        if(nums.size() < 1) return;
        sum[0] = nums[0];
        for(int i = 1; i< nums.size(); i++){
            sum[i] = nums[i]+sum[i-1];
        }
    }

    void update(int i, int val) {
        int ori = i==0 ? sum[i]:sum[i]-sum[i-1];
        int add = val-ori;
        for(int j = i; j < sum.size(); j++){
            sum[j] +=add;
        }
        
    }

    int sumRange(int i, int j) {
        return sum[j]-sum[i-1];
        
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
