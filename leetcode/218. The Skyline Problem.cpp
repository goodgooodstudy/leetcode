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



class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> criticals;
        for(auto p : buildings){
            criticals.emplace_back(p[0],p[2]);
            criticals.emplace_back(p[1],-p[2]);
        }
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){return a.first < b.first || a.first == b.first && a.second > b.second;};
        sort(criticals.begin(), criticals.end(),cmp);
        multiset<int> heights;
        vector<pair<int, int>> rst;

        for(auto p : criticals){

            if(p.second > 0){
                
                if(heights.empty()||p.second > *heights.rbegin()){
                    rst.emplace_back(p.first,p.second);

                }
                heights.insert(p.second);
            }
            else{
                heights.erase(heights.find(-p.second));
                if(heights.empty()){
                    rst.emplace_back(p.first,0);

                }
                else if( -p.second > *heights.rbegin()){
                    rst.emplace_back(p.first, *heights.rbegin());

                }
            }
        }
        return rst;
        
        
    }
};
