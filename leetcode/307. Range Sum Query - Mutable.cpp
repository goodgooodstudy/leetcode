class NumArray {
private:
    vector<int> BIT;
    vector<int> n;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        if(n < 1) return;
        this->BIT = vector<int>(n+1, 0);
        this->n = vector<int>(n,0);
        for(int i = 0; i < nums.size(); i++){
            update(i, nums[i]);
        }
        
    }

    void update(int i, int val) {
        int add = val-n[i];
        n[i] = n[i]+add;
        i++;
        while(i < BIT.size()){
            BIT[i] += add;
            i = i + (i&(-i));
        }
    }
    int getSum(int i){
        i++;
        int total = 0;
        while(i >0){
            total += BIT[i];
            i = i - (i&(-i));
        }
        return total;
    }
    int sumRange(int i, int j) {
        int s1 = 0, s2 = 0;
        if(i-1>=0) s1 = getSum(i-1);
        s2 = getSum(j);
        return s2-s1;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
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
