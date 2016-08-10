class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;
        int n = words.size(),len = words[0].size();
        unordered_map<string, int> cnts;
        for( string w : words){cnts[w]++;}
        for(int i = 0; i < s.size() - n*len+1; i++){
            unordered_map<string, int>seen;
            int j = 0;
            for(; j < n; j++){
                string cur = s.substr(i+j*len,len);
                seen[cur]++;
                if(seen[cur] > cnts[cur]) break;
            }
            if(j == n) res.push_back(i);
        }
        return res;
        
    }
};
