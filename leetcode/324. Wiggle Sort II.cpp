class Solution {
public:
// void wiggleSort(vector<int>& nums) {
//     vector<int> sorted(nums);
//     sort(sorted.begin(), sorted.end());
//     for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
//         nums[i] = sorted[i&1 ? k++ : j++];
// }
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int s = 0, l = nums.size()%2 ==0?nums.size()/2:nums.size()/2+1;
        for(int i = nums.size()-1; i >=0;i--){
            if(i%2 ==1){
                nums[i] = sorted[l++];
            }
            else{
                nums[i] = sorted[s++];
            }
           
        }
    }
};
