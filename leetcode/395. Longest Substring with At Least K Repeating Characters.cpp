class Solution {
public:
    vector<string> split(string s, char c){
        vector<string> rst;
        string cur;
        stringstream ss(s);
        while(getline(ss, cur, c)){
            rst.push_back(cur);
        }
        return rst;
    }
    int longestSubstring(string s, int k) {
       unordered_map<char, int> mp;
       for(int i = 0; i < s.size(); i++){
           mp[s[i]]++;
       }
       for(auto p : mp){
           if(p.second < k){
               vector<string> substr = split(s, p.first);
               int mx = 0;
               for(auto sub : substr){
                   mx = max(mx, longestSubstring(sub,k));
               }
               return mx;
               
           }
       }
       return s.size();
    }
};
