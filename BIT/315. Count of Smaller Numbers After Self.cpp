/**
* @Author: lcy
* @Date:   2016-10-27T13:43:16-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



// 315. Count of Smaller Numbers After Self   QuestionEditorial Solution  My Submissions
// Total Accepted: 20894
// Total Submissions: 63538
// Difficulty: Hard
// Contributors: Admin
// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
// Given nums = [5, 2, 6, 1]
//
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Return the array [2, 1, 1, 0].

// we insert number from end to front to its supposed location (from small to large), and count how much are in front of it(less than the number).
//  count we can use BIT to achieve O(log n)
// location we can use sort to  arrange.
class Solution {
private:
    vector<int> sum;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        sum = vector<int>(n+1,0);
        unordered_map<int, int> argIdx;
        vector<int> cp(nums);
        sort(cp.begin(), cp.end());
        for(int i = 0; i < n; i++){
            argIdx[cp[i]] = i+1;
        }
        for(int i = n-1; i >=0; i--){
            cp[i] = getSum(argIdx[nums[i]]-1);
            add(argIdx[nums[i]],1);
        }
        return cp;

    }
    void add(int idx, int val){
        idx++;
        while(idx < sum.size()){
            sum[idx]+=val;
            idx += idx&(-idx);
        }
    }
    int getSum(int idx){
        idx++;
        int total = 0;
        while(idx > 0){
            total += sum[idx];
            idx -= idx&(-idx);
        }
        return total;
    }

};
