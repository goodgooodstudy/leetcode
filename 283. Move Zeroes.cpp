class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int zeros = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i] == 0) zeros++;
    //         else{
    //             if(zeros>0){
    //                 nums[i-zeros] = nums[i];
    //             }
    //         }
    //     }
    //     for(int i = nums.size()-1; i>=int(nums.size()-zeros) && i>=0; i--){  //unsigned-signed -> unsigned>=0
    //         // cout << i-(nums.size()-zeros)<<endl;
    //         nums[i] = 0;
    //     }
    // }
    void moveZeroes(vector<int>& nums) {
        int last = 0, cur = 0;
        while(cur < nums.size()){
            if(nums[cur]!=0){
                swap(nums[last],nums[cur]);
                last++;
                cur++;
            }
            else{
                cur++;
            }
        }
    }
};
