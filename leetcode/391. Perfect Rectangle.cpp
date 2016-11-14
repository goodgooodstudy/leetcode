class Solution {
public:
struct interval{
    int start;
    int end;
    interval(int s, int e):start(s),end(e){};
};
struct edge{
    int t;
    interval e;
    edge(int t_, interval i_) : t(t_), e(i_) {};
};
struct cmp_edge{
  bool operator()(edge a, edge b){
      return a.t > b.t;
  }  
};
struct cmp_interval{
    bool operator()(interval a, interval b){
        return a.start < b.start;
    }
};
bool isRectangleCover(vector<vector<int>>& rectangles) {
    priority_queue<edge, vector<edge>, cmp_edge> q;   
    set<interval, cmp_interval> active_intervals;
    int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
    int areas = 0;
    for(auto rect : rectangles){
        areas += (rect[2]-rect[0])*(rect[3]-rect[1]);
        minx = min(minx, rect[0]);
        miny = min(miny, rect[1]);
        maxx = max(maxx, rect[2]);
        maxy = max(maxy, rect[3]);
        q.emplace(2*rect[0]+1, interval(rect[1], rect[3]));
        q.emplace(2*rect[2], interval(rect[1], rect[3]));
    }
    while(!q.empty()){
        int t = q.top().t;
        interval i = q.top().e;
        if(t%2){
            auto it = active_intervals.lower_bound(i);
            if(it!=active_intervals.end() && it->start < i.end) return false;
            if(it!=active_intervals.begin() && prev(it)->end > i.start) return false;
            active_intervals.insert(i);
        }
        else{
            active_intervals.erase(i);
        }
        q.pop();
    }
    return areas == (maxx-minx)*(maxy-miny);
    
}
};
