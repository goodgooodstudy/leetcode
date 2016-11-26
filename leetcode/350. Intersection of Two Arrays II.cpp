// 1.   What if the given array is already sorted? How would you optimize your algorithm?
// two pointer
//
// 2.   What if nums1's size is small compared to nums2's size? Which algorithm is better?
// for n1 binary search(nums2)
//
// 3.   What if elements of nums2 are stored on disk, and the memory is
// limited such that you cannot load all elements into the memory at
// once?
// If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, read chunks of array that fit into the memory, and record the intersections.
//
// If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort), then read 2 elements from each array at a time in memory, record intersections.



//hash m_map
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i : nums1){
            mp[i]++;
        }
        vector<int> rst;
        for(int i : nums2){
            if(mp[i] > 0){
                rst.push_back(i);
                mp[i]--;
            }
        }
        return rst;
    }
};


//two pointer
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(), nums2.end());
       int idx1 = 0, idx2 = 0;
       vector<int> rst;
       while(idx1 < nums1.size() && idx2 < nums2.size()){
           if(nums1[idx1] == nums2[idx2]){
               rst.push_back(nums1[idx1]);
               idx1++, idx2++;
           }
           else if(nums1[idx1] < nums2[idx2]){
               idx1++;
           }
           else{
               idx2++;
           }
       }
        return rst;
    }
};
//binary search if nums2 big , and idx2 from last index 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(), nums2.end());
       int idx1 = 0;
       auto idx2 = nums2.begin();
       vector<int> rst;
       while(idx1 < nums1.size() ){
           idx2 = lower_bound(idx2, nums2.end(), nums1[idx1]);
           if(idx2!=nums2.end() && *idx2 == nums1[idx1]){
               rst.push_back(nums1[idx1]);
               idx2++;
           }
           idx1++;
       }
        return rst;
    }
};
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
