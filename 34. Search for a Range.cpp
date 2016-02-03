class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        bool find = false;
        int i = 0;
        for (; i < nums.size(); i++){
            if(!find && nums[i] == target){
                find = true;
                result.push_back(i);
            }
            if(find && nums[i]!=target){
                result.push_back(i-1);
                break;
            }
        }
        
        if(find && i == nums.size()){
            result.push_back(nums.size()-1);
        }
        if(!find){
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
        
        
    }
};

class Solution {
private:
    int binarySearchLow(vector<int>& nums, int begin, int end,int target){
        if(begin > end) return begin;
        int mid = begin + (-begin+end)/2;
        if(nums[mid] < target) return binarySearchLow(nums, mid+1, end, target);
        else return binarySearchLow(nums,begin, mid-1, target);
    }
    int binarySearchHigh(vector<int>& nums, int begin, int end, int target){
        if(begin > end) return end;
        int mid = begin+ (-begin+end)/2;
        if(nums[mid] > target) return binarySearchHigh(nums, begin, mid-1, target);
        else return binarySearchHigh(nums, mid+1, end, target);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty()) return res;
        int high = binarySearchHigh(nums, 0, nums.size() -1,target);
        int low = binarySearchLow(nums,  0, nums.size() - 1,target);
        if(high >= low)
        {
            res[0] = low;
            res[1] = high;
            return res;
        }
        return res;
    }
        
};
