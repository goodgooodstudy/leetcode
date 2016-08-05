class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> h;
        for(int i = 0; i<nums.size(); i++){
            if(h.size()<k){
                h.push(nums[i]);
            }
            else{
                if(nums[i]>h.top()){
                    h.pop();
                    h.push(nums[i]);
                }
            }
        }
        return h.top();
        
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> h(nums.begin(), nums.end());
        for(int i = 0; i<k-1; i++){
            h.pop();
        }
       
        return h.top();
        
    }
};
