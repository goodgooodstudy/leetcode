class Solution {
public:
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int t1 = t.size();
        vector<vector<int>> cnt(s1+1, vector<int>(t1+1,0));
        for(int i = 0; i < s1+1; i++)   cnt[i][0]=1;
        for(int i = 1; i < s1+1; i++){
            for(int j = 1; j < t1+1; j++){
                if(s[i-1] == t[j-1]){
                    cnt[i][j] = cnt[i-1][j-1] + cnt[i-1][j];
                }
                else{
                    cnt[i][j] = cnt[i-1][j];
                }
            }
        }
        return cnt[s1][t1];
        
    }
};
