//判断mid和end，因为有两个元素的时候，mid就是begin，判断mid和begin有问题
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0; 
        int end = nums.size()-1;
        while(begin < end){
            int mid = (begin+end)/2;
            if(nums[mid] < nums[end]){
                end = mid;
            }
            else{
                begin = mid+1;
            }
        }
        return nums[begin];
        
    }
    
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums,0,nums.size()-1);
        
    }
    int findMin(vector<int>& nums, int begin, int end){
        if(begin >  end) return INT_MAX;
        int mid = (begin+end)/2;
        int res;
        if(nums[begin] <= nums[mid]){
            int l= nums[begin];
            int r = findMin(nums,mid+1,end);
            res = min(l,r);
        }
        else{
            int r = nums[mid];
            int l = findMin(nums,begin,mid-1);
            res = min(l,r);
        }
        return res;
    }
};
