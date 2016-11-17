class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.size() == 0) return true;
        double mid = 0;
        int minx = INT_MAX;
        int maxx = INT_MIN;
        unordered_map<int, unordered_map<int, int>> dict;
        for(auto p:points){
            minx = min(p.first, minx);
            maxx = max(p.first, maxx);
            dict[p.first][p.second]++;
        }
        mid = maxx+minx; //不能用所有x的和，因为会有重复的点，中心就变了，但是有允许重复的点，两个对一个
        for(auto p:points){
            int otherx = mid-p.first;
            int othery = p.second;
            if(dict.count(otherx) == 0 || dict[otherx].count(othery) == 0) return false;
        }
        return true;
    }
};
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
