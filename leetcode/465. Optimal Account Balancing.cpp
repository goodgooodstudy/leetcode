class Solution {
private:
    vector<long> deb;
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> debits;
        for(auto trans : transactions){
            debits[trans[0]] -= trans[2];
            debits[trans[1]] += trans[2];
        }
        for(auto p : debits){
            if(p.second != 0) deb.push_back(p.second);
        }
        return dfs(0);
    }
    int dfs(int s){
        while(s<deb.size() && deb[s]== 0) s++;
        int prev = 0;
        int res = INT_MAX;
        for(long i = s+1; i < deb.size(); i++){
            if( deb[i]!=prev && (deb[i]*deb[s]) < 0){
                prev = deb[i];
                deb[i] += deb[s];
                res = min(res, 1 + dfs(s+1));
                deb[i] -= deb[s];             
            }
        }
        return res == INT_MAX?0:res;
    }
};
