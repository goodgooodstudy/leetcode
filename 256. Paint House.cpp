/**
* @Author: lcy
* @Date:   2016-10-26T17:07:56-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 256. Paint House   QuestionEditorial Solution  My Submissions
// Total Accepted: 13518
// Total Submissions: 29933
// Difficulty: Medium
// Contributors: Admin
// There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//
// The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
//
// Note:
// All costs are positive integers.
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        int color1 = costs[0][0];
        int color2 = costs[0][1];
        int color3 = costs[0][2];

        for(int i = 1; i < costs.size(); i++){
            int pre1 = color1, pre2 = color2, pre3 = color3;
            color1 = min(pre2, pre3)+costs[i][0];
            color2 = min(pre1, pre3)+costs[i][1];
            color3 = min(pre1, pre2)+costs[i][2];
        }
        return min(min(color1, color2), color3);
    }
};
