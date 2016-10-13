class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> map;
        vector<string> route;
        int size = tickets.size()+1;
        route.push_back("JFK");
        for (const auto& t: tickets){
            map[t.first][t.second]++;
        }
        dfs("JFK",map,route,size);
        return route;
        
    }
    bool dfs(string cur, unordered_map<string, map<string, int>>& map, vector<string>& route, int size ){
        if(route.size() == size) return true;
        if(route.size() > size) return false;
        
//         for(auto& next : map[cur]){
//             if(next.second > 0){
//                 next.second --;
                
//                 route.push_back(next.first);
//                 if(dfs(next.first, map, route, size)) return true;
//                 route.pop_back();
//                 next.second ++;
//             }
//         }
        for(auto ticket = map[cur].begin(); ticket!=map[cur].end();ticket++){
            if(ticket->second!=0){
                ticket->second --;
                route.push_back(ticket->first);
                if(dfs(ticket->first, map, route, size))return true;
                route.pop_back();
                ticket->second++;
            }
        }
        return false;
        
    }
};
