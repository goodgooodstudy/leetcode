/**
* @Author: lcy
* @Date:   2016-10-27T18:16:15-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cnt(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j =0, head =0, tail = 0; j < n; j++){
                cnt[i][j] = grid[i][j] != '0' ? 0: head+cnt[i][j];
                cnt[i][n-j-1] = grid[i][n-1-j] !='0'? 0: tail+cnt[i][n-j-1];
                head = (grid[i][j] == 'W')? 0: head+ (grid[i][j] =='E' ? 1:0);
                tail = (grid[i][n-j-1] == 'W')? 0:tail+ (grid[i][n-j-1] == 'E'?1:0);
            }
        }
        for(int j = 0; j < n; j++){
            for(int i = 0, up = 0, bottom = 0; i < m; i++){
                cnt[i][j] = grid[i][j] != '0'? 0: up+cnt[i][j];
                cnt[m-1-i][j] = grid[m-1-i][j] != '0'?0:bottom+cnt[m-1-i][j];
                up = (grid[i][j] == 'W') ? 0: up + (grid[i][j] == 'E' ? 1:0);
                bottom = (grid[m-1-i][j] == 'W') ? 0:bottom + (grid[m-1-i][j] == 'E' ? 1: 0);
            }
        }
        int mx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mx = max(mx, cnt[i][j]);
            }
        }
        return mx;
    }
};
