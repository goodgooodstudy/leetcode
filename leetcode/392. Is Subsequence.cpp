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

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = 0, t1 = 0;
        while(t1 < t.size()){
            if(s[s1] == t[t1]){
                s1++;
                t1++;
            }
            else{
                t1++;
            }
        }
        return s1 == s.size();
    }
};
