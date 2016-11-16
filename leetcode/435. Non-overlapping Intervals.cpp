/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto cmp = [](Interval a, Interval b){return a.start < b.start || a.start == b.start && a.end < b.end;};
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int cnt = 0;
        int pre = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < intervals[pre].end){
                if(intervals[i].end < intervals[pre].end){
                    pre = i;
                }
                cnt++;
            }
            else pre = i;
        }
        return cnt;
    }
};
