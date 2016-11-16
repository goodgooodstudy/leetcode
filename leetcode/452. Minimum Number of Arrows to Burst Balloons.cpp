class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0) return 0;
        auto cmp = [](pair<int, int> a, pair<int,int> b){return a.first < b.first;};
        sort(points.begin(), points.end(), cmp);
        int cnt = 0;
        int right = points[0].second;
        for(int i = 1; i < points.size(); i++){
            if(points[i].first <= right){
                right = min(right, points[i].second);
            }
            else{
                cnt++;
                right = points[i].second;
            }
        }
        return cnt+1;
    }
};
