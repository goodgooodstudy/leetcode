/**
* @Author: lcy
* @Date:   2016-09-03T12:50:54-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int index = 0, n = intervals.size();
        while(index < n && intervals[index].end < newInterval.start){
            res.push_back(intervals[index++]);
        }
        while(index < n && (intervals[index].start <= newInterval.end)){ //!!! newInterval may just before the intervals[idx]
            newInterval.start = min(newInterval.start,intervals[index].start);
            newInterval.end = max(newInterval.end,intervals[index].end);
            index++;
        }
        res.push_back(newInterval);
        while(index < n){
            res.push_back(intervals[index++]);
        }
        return res;


    }
};
