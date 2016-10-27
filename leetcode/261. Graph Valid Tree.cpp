/**
* @Author: lcy
* @Date:   2016-09-12T00:24:57-04:00
*/

// undirected graph cannot use topological to test whether acyclic(count will smaller than the real,beacuse no degrees be 0)
// if cyclic, the edges cannot be n-1(only one component)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n,-1);
        for(int i = 0; i < n; i++) root[i] = i;
        for(auto p : edges){
            int f = p.first;
            int s = p.second;
            while(root[f] != f) f = root[f];
            while(root[s] != s) s = root[s];
            if(f == s) return false;
            root[s] = f;
        }
        return edges.size() == n-1;

    }
};
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> v(n,vector<int>());

        for(auto edge:edges){
            v[edge.first].push_back(edge.second);
            v[edge.second].push_back(edge.first);
        }

        if(!dfs(visited,v, 0, -1)) return false;
        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }
        return true;

    }
    bool dfs(vector<bool>& visited, vector<vector<int>>& edges, int cur, int parent){
        if(visited[cur]) return false;
        visited[cur] = true;
        for(int i : edges[cur]){
            if(parent != i && !dfs(visited, edges, i,cur)) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
// if they have cycle, the edge must not be n-1
        if(edges.size() != n - 1)
        return false;
        int component=0;
        vector<int>v[n];
        vector<bool>visited(n,false);

        for(auto edge:edges){
            v[edge.first].push_back(edge.second);
            v[edge.second].push_back(edge.first);
        }

// count component
        for(int i=0;i<n;++i){
            if(!visited[i]){
                ++component;
                DFS(v,visited,i);
            }
        }
        return component==1;
    }
    void DFS(vector<int>v[],vector<bool>&visited,int indx){
        if(visited[indx])
        return;
        visited[indx]=true;
        for(int j=0;j<v[indx].size();++j){
            DFS(v,visited,v[indx][j]);
        }
    }
};
