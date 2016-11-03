/**
* @Author: lcy
* @Date:   2016-09-04T12:48:28-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.empty()){
            if(lower == upper) res.push_back(to_string(lower));
            else res.push_back(to_string(lower)+"->"+to_string(upper));
            return res;
        }
        nums.insert(nums.begin(),lower-1);
        nums.insert(nums.end(),upper+1);

        for(int i = 1; i < nums.size();i++){

            if(nums[i]<=nums[i-1]+1){
                continue;
            }
            else if(nums[i] - nums[i-1] == 2){
                res.push_back(to_string(nums[i]-1));
            }
            else{
                res.push_back(to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1));
            }

        }
        return res;

    }
};

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> rst;
        if(nums.size() == 0){
            if(upper == lower) rst.push_back(to_string(upper));
            if( lower < upper) rst.push_back(to_string(lower)+"->"+to_string(upper));
            return rst;
        }
        if(nums[0]-lower == 1) rst.push_back(to_string(lower));
        if((double)nums[0]-(double)lower >= 2) rst.push_back(to_string(lower)+"->"+to_string(nums[0]-1));
        for(int i = 1; i < nums.size(); i++){

            if((double)nums[i] - (double)nums[i-1] <= 1) continue;
            else if((double)nums[i] - (double)nums[i-1] == 2) rst.push_back(to_string(nums[i-1]+1));
            else rst.push_back(to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1));
        }
        if((double)upper - (double)nums.back() == 1) rst.push_back(to_string(upper));
        if((double)upper - (double)nums.back() >= 2) rst.push_back(to_string(nums.back()+1)+"->"+to_string(upper));
        return rst;
    }
};
