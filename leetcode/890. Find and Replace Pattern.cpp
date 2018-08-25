class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(string s : words){
            if(F(s) == F(pattern)){
                result.push_back(s);
            }
        }
        return result;
    }
    string F(string s){
        unordered_map<char, int> mp;
        for(char c : s) if(!mp.count(c)) mp[c] = mp.size();
        string result;
        for(char c : s){
            result += 'a' + mp[c];
        }
        return result;
    }
};