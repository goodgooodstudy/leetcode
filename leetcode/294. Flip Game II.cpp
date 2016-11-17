class Solution {
public:
    bool canWin(string s) {
        if(s.size() < 2) return false;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1] && s[i] == '+'){
                s[i] = s[i-1] = '-';
                if(!canWin(s)) return true;
                s[i] = s[i-1] = '+';
            }
        }
        return false;
    }

};

class Solution {
private:
    unordered_map<string, bool> mp;
public:
    bool canWin(string s) {
        if(mp.count(s)) return mp[s];

        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1] && s[i-1] == '+'){
                string tmp(s);
                tmp[i] = '-';
                tmp[i-1] = '-';
                if(!canWin(tmp)) return true;
            }
        }
        mp[s] = false;
        return false;
    }
};
