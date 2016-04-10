class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        
        if(total & 0x1){
            return findKth(nums1,0, nums2, 0,total/2+1);
        }
        else{
            return (findKth(nums1, 0,nums2, 0,total/2)+findKth(nums1, 0,nums2,0, total/2 +1))/2.0;
        }
        
    }
    int findKth(vector<int>& nums1, int s1, vector<int>& nums2, int s2,int k){
        int n1 = nums1.size() - s1;
        int n2 = nums2.size() - s2;
        if(n1 > n2) return findKth(nums2, s2, nums1, s1, k);
        if(n1 == 0) return nums2[k-1+s2];
        if(k == 1) return min(nums1[0+s1],nums2[0+s2]);
        
        int ia = min(k/2,n1); 
        int ib = k -ia;
        if(nums1[s1+ia-1] == nums2[s2+ib-1]) return nums1[s1+ia-1];
        else if(nums1[s1+ ia-1] < nums2[s2+ib-1]){
            return findKth(nums1,ia+s1, nums2, s2, k-ia);
        }
        else{
            return findKth(nums1,s1, nums2,s2+ib, k-ib);
        }
        
    } 
};
