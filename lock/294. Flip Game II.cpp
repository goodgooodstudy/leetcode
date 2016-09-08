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
