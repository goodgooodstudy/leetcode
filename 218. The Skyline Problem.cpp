class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int>coords;
        multiset<int>heights = {0};
        vector<pair<int, int>> rst;
        for(const vector<int>& building: buildings){
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], building[2]);
        }
        int x = -1;
        int y = 0;
        for(const pair<int,int>& p: coords){
            if((x >= 0) && (p.first != x) && (rst.empty() || rst.rbegin()->second != y)){
                rst.emplace_back(x, y);
            }
            if(p.second >= 0){
                heights.insert(p.second);
            }else{
                heights.erase(heights.find(-p.second));
            }
            x = p.first;
            y = *heights.rbegin();
            
        }
        if(!rst.empty()){
            rst.emplace_back(x,0);
        }
        return rst;
        
    }
};
