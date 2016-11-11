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
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //可以sort， 然后前一半后一半， 中小大中排列
        // If the above description is unclear, maybe this explicit listing helps:

// Accessing A(0) actually accesses nums[1].
// Accessing A(1) actually accesses nums[3].
// Accessing A(2) actually accesses nums[5].
// Accessing A(3) actually accesses nums[7].
// Accessing A(4) actually accesses nums[9].
// Accessing A(5) actually accesses nums[0].
// Accessing A(6) actually accesses nums[2].
// Accessing A(7) actually accesses nums[4].
// Accessing A(8) actually accesses nums[6].
// Accessing A(9) actually accesses nums[8].
        int n = nums.size();
        auto midptr = nums.begin() + n/2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        #define A(i) nums[(1+2*i)%(n|1)]
        
        int i = 0, j = n-1;
        int k = 0;
        while(k <= j){
            if(A(k) > mid){
                swap(A(i++), A(k++));
            }
            else if(A(k) < mid){
                swap(A(k), A(j--));
            }
            else k++;
        }
    }
};
