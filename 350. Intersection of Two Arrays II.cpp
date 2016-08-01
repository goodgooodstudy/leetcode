class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1;
        vector<int> res;
        for(auto n:nums1){
            if(n1.count(n)){
                n1[n]++;
            }
            else{
                n1[n]=1;
            }
        }
        for(auto n2:nums2){
            if(n1.count(n2)&&n1[n2]>0){
                res.push_back(n2);
                n1[n2] --;
            }
        }
        return res;
    }
};
