class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int count0 = 0, count1 = 0, count2 = 0;
        for(auto num: nums){
            if(num == 0) count0++;
            if(num == 1) count1++;
            if(num == 2) count2++;
        }
        for(int i = 0; i < count0; i++){
            nums[i] = 0;
        }
        for(int i = count0; i < count0+count1; i++){
            nums[i] =1;
        }
        for(int i = count0+count1; i < count0+count1+count2; i++){
            nums[i] = 2;
        }
        
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, second = nums.size()-1;
        for(int i = 0; i <= second; ){
           if(nums[i] == 0) swap(nums[i++], nums[zero++]);
           else if(nums[i] == 2) swap(nums[i], nums[second--]);
           else i++;
           

        }
        
    }
};
