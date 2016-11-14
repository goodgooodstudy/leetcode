/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<pair<int, int>, int> slopes;
        int n = points.size();
        int mx = 0;
        for(int i = 0; i < n; i++){
            slopes.clear();
            int duplicates = 1;

            for(int j = i+1; j < n; j++){
                if(points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicates++;
                    continue;
                }
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int gcd = GCD(dx, dy);
                slopes[make_pair(dx/gcd,dy/gcd)]++;
            }
            mx = max(mx, duplicates);
            for(auto p : slopes){
                if(p.second + duplicates > mx){
                    mx = p.second+duplicates;
                }
            }
        }
        return mx;
    }
    int GCD(int n1, int n2){
        while(n2){
            int tmp = n1%n2;
            n1 = n2;
            n2 = tmp;
        }
        return n1;
    }
};
