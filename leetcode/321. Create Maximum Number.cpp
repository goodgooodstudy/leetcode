/**
* @Author: lcy
* @Date:   2016-09-03T12:50:54-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k,0);
        for(int i = max(0,  k-(int)nums2.size()); i <= min(k, (int)nums1.size() ); i++){

            vector<int> res1 = get_max_sub_array(nums1, i);
            vector<int> res2 = get_max_sub_array(nums2, k-i);

            int pos1 = 0, pos2 = 0, tpos = 0;
            vector<int> res(k,0);
            while(pos1 < res1.size() || pos2 < res2.size()){
                res[tpos++] = greater(res1, pos1, res2, pos2)? res1[pos1++]: res2[pos2++];
            }
            if(greater(res,0,ans,0)){
                ans = res;
            }

        }
        return ans;
    }

    bool greater(vector<int>& nums1, int pos1, vector<int>& nums2, int pos2){
        int i = pos1, j = pos2;
        for(; i < nums1.size() && j < nums2.size(); i++,j++){
            if(nums1[i] > nums2[j]) return true;
            if(nums1[i] < nums2[j]) return false;
        }
        return nums1.size()!=i;
    }
    vector<int> get_max_sub_array(vector<int>& nums, int k){
        vector<int> res(k,0);
		int len = 0 , n = nums.size();
		for (int i = 0; i < n; i++) {
			while (len && len + n - i > k && nums[i] > res[len - 1])
				len--;
			if (len < k)
				res[len++] = nums[i];
		}
		return res;
    }
};
