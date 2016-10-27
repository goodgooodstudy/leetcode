class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
        
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        if(s.size()!=t.size()) return false;
        for(int i = 0; i < s.size();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto p:m){
            if(p.second) return false;
        }
        return true;
        
    }
};
