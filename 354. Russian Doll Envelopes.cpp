class Solution {
       static bool cmp(pair<int, int> p1, pair<int, int>p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        int n = envelopes.size();
        if(n==0) return 0;
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> dp(n,1);
        int mx = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(envelopes[i].first> envelopes[j].first &&envelopes[i].second > envelopes[j].second){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
        
    }
};
