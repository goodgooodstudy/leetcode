class Solution {
public:
    string longestPalindrome(string s) {
        int maxL = 0;
        int len = s.size();
        int dp[len][len];
        memset(dp, 0, len*len*sizeof(int));
        int start = 0, end = 0;
        for(int j = 0; j< len;j++){
            for (int i = 0; i <= j; i++){
                if(i == j)dp[i][j] = 1;
                if(j == i+1 && s[i]==s[j]) dp[i][j] =1;
                if((j>i+1) && dp[i+1][j-1] && (s[i] == s[j])) dp[i][j] = 1;
                if(dp[i][j] == 1 && j-i+1 > maxL){
                        maxL = j-i+1;
                        start = i;
                        end = j;
                }
            }
        }
        
        return s.substr(start, maxL);
        
    }
};
