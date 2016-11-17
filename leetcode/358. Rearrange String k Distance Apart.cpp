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

class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k==0) return str;
        int n = str.size();
        unordered_map<char, int> mp;
        auto cmp = [](pair<char, int> a, pair<char, int> b){return a.second < b.second||a.second == b.second && a.first > b.first;};
        priority_queue<pair<char, int>,vector<pair<char, int>>,decltype(cmp)> q(cmp);
        for(auto c : str) mp[c]++;
        for(auto item: mp) q.push(item);
        string rst;
        while(!q.empty()){
            int l = min(k, n);
            vector<pair<char, int>> tmp;
            for(int i = 0; i < l; i++){
                // cout << rst<<endl;
                if(q.empty()) return "";
                auto cur = q.top();
                q.pop();
                rst.push_back(cur.first);
                cur.second --;

                if(cur.second > 0){
                    tmp.push_back(cur);
                }
                n--;
            }
            for(auto i : tmp) q.push(i);
        }
        return rst;
    }
};
