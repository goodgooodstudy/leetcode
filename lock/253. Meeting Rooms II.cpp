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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for(auto i : intervals){
            mp[i.start]++;
            mp[i.end]--;
        }
        int rooms = 0, maxrooms = 0;
        for(auto p : mp){
            rooms+=p.second;
            maxrooms = max(maxrooms, rooms);
        }
        return maxrooms;
    }
};
