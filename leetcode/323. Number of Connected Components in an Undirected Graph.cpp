/**
* @Author: lcy
* @Date:   2016-09-11T21:46:35-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 323. Number of Connected Components in an Undirected Graph   QuestionEditorial Solution  My Submissions
// Total Accepted: 15637
// Total Submissions: 34365
// Difficulty: Medium
// Contributors: Admin
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
//
// Example 1:
//      0          3
//      |          |
//      1 --- 2    4
// Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
//
// Example 2:
//      0           4
//      |           |
//      1 --- 2 --- 3
// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
//
// Note:
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
// dfs, union find both okay 
class Solution {
private:
    vector<int> root;
    int findroot(int node){
        if(root[node] == node) return node;
        root[node] =  findroot(root[node]);
        return root[node];
    }
    void unionnodes(int node1, int node2){
        root[findroot(node1)] = findroot(node2);
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        for(int i = 0; i < n; i++) root.push_back(i);
        for(auto pair : edges){
            unionnodes(pair.first, pair.second);
        }
        set<int> cnt;
        for(int i = 0; i <n; i++){
            cnt.insert(findroot(i));
        }
        return cnt.size();

    }
};
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n, -1);
        int islands = n;
        for(int i = 0; i < n; i++){
            root[i] = i;
        }
        for(auto edge: edges){
            int rootX = findroot(edge.first, root);
            int rootY = findroot(edge.second, root);
            if(rootX!=rootY){
                islands--;
                root[rootX] = rootY;
            }
        }
        return islands;

    }
    int findroot(int idx, vector<int>& root){
        while(root[idx] != idx){
            root[idx] = root[root[idx]];
            idx = root[idx];
        }
        return idx;
    }
};
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> v;
        for(auto p : edges){
            v[p.first].push_back(p.second);
            v[p.second].push_back(p.first);
        }
        vector<bool> visited(n, false);
        int islands = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                islands++;
                dfs(i, v, visited);
            }
        }
        return islands;
    }
    void dfs(int i, unordered_map<int, vector<int>>& edges, vector<bool>& visited){
        visited[i] = true;
        for(auto neigh:edges[i]){
            if(!visited[neigh]) dfs(neigh, edges, visited);
        }
    }
};
