class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tidx = 0;
        for(int i = 0; i < s.size(); i++){
            while(tidx < t.size() && t[tidx]!=s[i]) tidx++;
            if(tidx >= t.size()) return false;
            tidx++;
        }
        return true;
        
    }
};
