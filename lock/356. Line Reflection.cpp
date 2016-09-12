class Solution {
public:

    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, set<int>> mp;
        int mn = INT_MAX, mx = INT_MIN;
        for(auto p : points){
            mn = min(mn, p.first);
            mx = max(mx, p.first);
            mp[p.first].insert(p.second);
        }
        double x = (double)(mx + mn)/2.0;
        
        for(auto p : points){
            int t = 2 * x - p.first;
            if(!mp.count(t) || !mp[t].count(p.second)) return false;
        }
        return true;
    }
};
