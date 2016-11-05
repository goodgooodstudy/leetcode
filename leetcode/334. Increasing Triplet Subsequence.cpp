/**
* @Author: lcy
* @Date:   2016-10-24T09:56:37-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() <3) return false;
        int a1 = 0x7fffffff, a2 = 0x7fffffff;
        for(int num:nums){
            if(num <= a1) a1 = num; //!!! == important
            else if(num <= a2) a2 = num;
            else return true;
        }
        return false;

    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(res.empty() || nums[i] > res.back()){
                res.push_back(nums[i]);
                continue;
            }
            int l = 0, r = res.size()-1;
            while(l < r){
                int mid = l + (r-l)/2;
                if(res[mid] < nums[i]) l = mid+1;
                else r = mid;
            }
            res[l] = nums[i];
        }
        return res.size() >= 3;
    }
};
