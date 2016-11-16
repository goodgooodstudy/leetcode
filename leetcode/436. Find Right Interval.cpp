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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> h;
        vector<int> rst;
        for(int i = 0; i < intervals.size(); i++){
            h[intervals[i].start] = i;
        }
        for(int i = 0; i < intervals.size(); i++){
            auto it = h.lower_bound(intervals[i].end);
            if(it==h.end()){
                rst.push_back(-1);
            }
            else{
                rst.push_back(it->second);
            }
        }
        return rst;
    }
};
