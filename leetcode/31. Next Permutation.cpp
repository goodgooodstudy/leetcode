class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i= nums.size()-1;
        while(i-1>=0){
            if(nums[i-1]<nums[i] ){
                break;
            }
            i--;
        }
        if(i==0){
             reverse(nums.begin(),nums.end());
             return;
        }
        int j = nums.size()-1;
        for(; j>i-1;j--){
            if(nums[j] > nums[i-1]){
                break;
            }
        }
        swap(nums[i-1],nums[j]);
        reverse(nums.begin()+i, nums.end());

    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
}
