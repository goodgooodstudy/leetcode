/**
* @Author: lcy
* @Date:   2016-10-29T10:48:03-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 406. Queue Reconstruction by Height   QuestionEditorial Solution  My Submissions
// Total Accepted: 7185
// Total Submissions: 13427
// Difficulty: Medium
// Contributors: Admin
// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//
// Note:
// The number of people is less than 1,100.
//
// Example
//
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
auto cmp = [](pair<int, int> a, pair<int, int> b){return a.first > b.first || (a.first == b.first && a.second < b.second);};
        sort(people.begin(), people.end(), cmp);
        vector<pair<int, int>> rst;
        for(auto p : people){
            rst.insert(rst.begin()+p.second, p); ///insert !! not emplace_back
        }
        return rst;

    }
};
