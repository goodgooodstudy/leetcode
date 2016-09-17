class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(auto s : strs){
            string cur(s);
            sort(cur.begin(), cur.end());
            mp[cur].push_back(s);
        }
        
        for(auto p : mp){
            res.push_back(p.second);
        }
        return res;
        
    }
};
