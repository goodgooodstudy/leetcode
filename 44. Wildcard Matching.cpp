class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.size(),pn = p.size();
        int si =0, pi = 0;
        int asterisk = -1, match;
        while(si < sn){
            if(pi<pn && (s[si] == p[pi] || p[pi] =='?')){
                si++;
                pi++;
            }
            else if(pi < pn && (p[pi]=='*')){
                asterisk = pi++;
                match = si;
            }
            else if(asterisk>=0){
                si = ++match;
                pi = asterisk+1;
            }
            else{
                return false;
            }
            
        }
        while(pi <pn &&p[pi] == '*') pi++;
        return pi == pn;
        
    }
};
