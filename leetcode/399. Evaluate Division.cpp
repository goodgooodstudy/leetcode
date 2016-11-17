class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> g;
        for(int i = 0; i < equations.size(); i++){
            g[equations[i].first][equations[i].second] = values[i];

            g[equations[i].first][equations[i].first] = 1;
            g[equations[i].second][equations[i].second] = 1;

            if(values[i]!=0){
                g[equations[i].second][equations[i].first] = 1/values[i];
            }
        }
        vector<double> rst;
        for(auto p : queries){
            unordered_set<string> visited;
            double cur = 1;
            if(g.count(p.first) && g.count(p.second)&&dfs(g, visited, p.first, p.second, cur)){
                rst.push_back(cur);
            }
            else{
                rst.push_back(-1);
            }
        }
        return rst;
    }
    bool dfs(unordered_map<string, unordered_map<string, double>>& g, unordered_set<string>& visited, string begin, string end, double& rst){
        if(visited.count(begin)){
            return false;
        }
        visited.insert(begin);
        if(begin == end){
            return true;
        }
        for(auto next : g[begin]){
            rst = rst*next.second;
            if(dfs(g, visited, next.first, end, rst)) return true;
            rst = rst/next.second;
        }
        visited.erase(begin);
        return false;
    }
};
