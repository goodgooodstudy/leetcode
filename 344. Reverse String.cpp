class Solution {
public:
    string reverseString(string s) {
        string res (s.size(), 0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            res[i] = s[n-i-1];
        }
        return res;
    }
};
