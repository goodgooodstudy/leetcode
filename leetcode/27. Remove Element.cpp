class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = remove(nums.begin(),nums.end(),val);
        nums.resize(distance(nums.begin(),it));
        return nums.size();
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int cnt = 0;
        int n = nums.size();
        int i = 0;
        while( i < n){
            if(nums[i] == val){
                nums[i]= nums[n-1];
                n--;
            }
            else{
                i++;
            }
        }
        return n;
        // for(int i = 0; i < nums.size()-first; i++){
        //     if(nums[i] == val){
        //         nums[i] = nums[nums.size()-1-first];
        //         first++;
        //         i--;
        //     }
        // }
        // return nums.size()-first;
        
    }
};
