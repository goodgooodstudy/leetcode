class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = remove(nums.begin(),nums.end(),val);
        nums.resize(distance(nums.begin(),it));
        return nums.size();
    }
};
