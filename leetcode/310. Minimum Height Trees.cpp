class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> g(n, vector<int>());
        vector<int> d(n,0);
        for(auto t : edges){
            g[t.first].push_back(t.second);
            d[t.first]++;
            g[t.second].push_back(t.first);
            d[t.second]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(d[i] == 1)q.push(i);
        }
        while(n>2){
            int sz = q.size();
            for(int i =0; i < sz; i++){
                int t = q.front();
                q.pop();
                --n;
                for(int i: g[t]){
                    --d[i];
                    if(d[i] == 1) q.push(i);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
        
    }
};
