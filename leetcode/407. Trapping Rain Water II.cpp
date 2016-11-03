/**
* @Author: lcy
* @Date:   2016-10-28T21:48:45-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 407. Trapping Rain Water II   QuestionEditorial Solution  My Submissions
// Total Accepted: 2623
// Total Submissions: 7780
// Difficulty: Hard
// Contributors: Admin
// Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
//
// Note:
// Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
//
// Example:
//
// Given the following 3x6 height map:
// [
//   [1,4,3,1,3,2],
//   [3,2,1,3,2,4],
//   [2,3,3,2,3,1]
// ]
//
// Return 4.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() == 0 || heightMap[0].size() == 0) return 0;
        auto cmp = [](pair<int, int> a, pair<int, int> b){return a.first > b.first;};
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!(i == 0 || i == m-1 || j == 0 || j == n-1)) continue;
                q.emplace(heightMap[i][j], i*n+j);
                visited[i][j] = true;
            }
        }
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};
        int total = 0;
        int mx = INT_MIN;
        while(!q.empty()){
            auto cur = q.top();
            int x = cur.second/n;
            int y = cur.second%n;
            mx = max(mx, cur.first);
            q.pop();
            for(auto dir : dirs){
                int x1 = x + dir.first;
                int y1 = y + dir.second;
                if(x1 < 0 || x1 >= m || y1 < 0 || y1 >=n || visited[x1][y1]) continue;
                visited[x1][y1] = true;
                if(mx > heightMap[x1][y1]) total += mx - heightMap[x1][y1];
                q.emplace(heightMap[x1][y1], x1*n+y1);
            }
        }
        return total;
    }
};
