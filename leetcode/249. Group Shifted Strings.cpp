class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, multiset<string>> m;
        vector<vector<string>> res;
        for(auto a : strings){
            string tmp="";
            for(char t : a){
                tmp += to_string((t+26-a[0])%26)+",";
            }
            m[tmp].insert(a);
        }
        for(auto p : m){
            res.push_back(vector<string>(p.second.begin(),p.second.end()));
        }
        return res;
        
    }
};
