class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniques;
        for(auto n:nums){
            if(uniques.count(n)) return true;
            uniques.insert(n);
        }
        return false;
        
    }
};
