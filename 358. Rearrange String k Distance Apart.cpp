class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k == 0) return str;
        string res;
        int n = str.size();
        unordered_map<char, int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto c : str) mp[c]++;
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.emplace(it->second,it->first);
        }
        
        while(!pq.empty()){
            vector<pair<int,char>> cache;
            int l = min(k, n);
            for(int i = 0; i < l; i++){
                if(pq.empty()) return "";
                auto cur = pq.top();
                pq.pop();
                res.push_back(cur.second);
                if(--cur.first > 0) cache.push_back(cur);
                n--;
            }
            
            for(auto c : cache) pq.push(c);
        }
        
        return res;
    }
};
