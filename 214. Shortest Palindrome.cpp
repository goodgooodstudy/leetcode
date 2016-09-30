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


class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0, j = 1;
        string rev(s);
        reverse(rev.begin(), rev.end());
        string ss;
        ss = s+"#"+rev;
        vector<int> len(ss.size(),0);
        while(j < ss.size()){
            if(ss[j] == ss[i]){
                len[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i==0){
                    len[j] = 0;

                    j++;
                } 
                else i = len[i-1];
            }
        }
        return rev.substr(0, s.size()- len[ss.size()-1])+s;
        
        
    }
   
};
