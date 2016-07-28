class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> possible(n+1, false);
        possible[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j+1 < i; j++){
                if(wordDict.count(s.substr(j, i-j)) && possible[j]) {
                    possible[i] = true;
                    break;
                }
            }
        }
        return possible[n];
        
    }
};
