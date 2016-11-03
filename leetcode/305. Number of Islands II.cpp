/**
* @Author: lcy
* @Date:   2016-09-06T21:41:58-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> roots(m*n,-1);
        vector<int> res;
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int island = 0;
        for(auto p : positions){
            int x = p.first, y = p.second, p_idx = n*x + y;
            roots[p_idx] = p_idx;
            ++island;

            for(auto dir: dirs){
                int row = x+dir.first, col = y+dir.second;
                int new_idx = n*row + col;
                if(row>=0 && row<m && col>=0 && col < n && roots[new_idx]!=-1){
                    int p_root = find(p_idx, roots), n_root = find(new_idx, roots);
                    if(p_root != n_root){
                        roots[p_root] = n_root;
                        --island;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }

    int find(int idx, vector<int>& roots){
        while(roots[idx]!=idx){
            roots[idx] = roots[roots[idx]];
            idx = roots[idx];
        }
        return idx;
        // if(root[idx] == idx) return idx;
        // root[idx] =  findroot(root[idx], root);
        // return root[idx];
    }
};
