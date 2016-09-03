class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        vector<int> next(l.size(),0);

        getNext(l,next);
        return rev_s.substr(0, s.size() - next[l.size()-1]) + s;
    }
    void getNext(string s, vector<int>& next){
        for(int i = 1; i < s.size() ;i++){
            int k = next[i-1];
            while(k > 0 && s[k]!=s[i]){
                k = next[k-1];
            }
            next[i] = k+(s[k] == s[i]);
        }
    }
};
