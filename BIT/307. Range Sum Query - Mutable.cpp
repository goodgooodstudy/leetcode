/**
* @Author: lcy
* @Date:   2016-10-27T13:16:55-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 307. Range Sum Query - Mutable   QuestionEditorial Solution  My Submissions
// Total Accepted: 21976
// Total Submissions: 118979
// Difficulty: Medium
// Contributors: Admin
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
// The update(i, val) function modifies nums by updating the element at index i to val.
// Example:
// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
// Note:
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

class NumArray {
private:
    vector<int> sum;
    vector<int> num;
public:
    NumArray(vector<int> &nums) {
        num = nums;
        int n = nums.size()+1;
        sum = vector<int>(n, 0);
        for(int i = 0; i < nums.size(); i++){
            add(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int change = val - num[i];
        num[i] = val;
        if(change != 0) add(i, change);
    }
    void add(int i, int val){
        i++;
        while(i < sum.size()){
            sum[i] += val;
            i += i&(-i);
        }
    }
    int getSum(int i){
        i++;
        int total = 0;
        while(i > 0){
            total += sum[i];
            i -= i&(-i);
        }
        return total;
    }
    int sumRange(int i, int j) {
        int total = getSum(j);
        if(i-1 >=0) total -= getSum(i-1);
        return total;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
