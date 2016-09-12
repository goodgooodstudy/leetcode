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
