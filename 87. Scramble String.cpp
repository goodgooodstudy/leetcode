class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size()!=s2.size()) return false;
        int len = s1.size();
        int cout[128] = {0};
        for(int i = 0; i < len; i++){
             cout[s1[i]]++;
             cout[s2[i]]--;
        }
        for(int i = 0; i < 128; i++){
            if(cout[i]!=0) return false;
        }
        
        for(int i = 1; i <= len-1; i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i))) return true;
            if(isScramble(s1.substr(0,i),s2.substr(len-i)) && isScramble(s1.substr(i),s2.substr(0,len-i))) return true;
        }
        
        return false;
    }
};
