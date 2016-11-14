class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int l1 =s.size(), l2 = t.size();
        if(l1 > l2) return isOneEditDistance(t, s);
        if(l1 < l2-1) return false;
        bool mismatch = false;
        for(int i = 0; i < l1; i++){
            if(s[i] != t[i]){
                if(l1 == l2) {
                    s[i] = t[i];
                }
                else{
                    s.insert(s.begin()+i,t[i]);
                }
                mismatch = true;
                break;
            }
        }
        if(mismatch) return s == t;
        else return l1+1 == l2;
    }
};
