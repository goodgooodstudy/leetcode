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

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size() == 1) return s;
        int mxLen = 1,min_start = 0;
        for(int i = 0; i < s.size(); i++){
            if(s.size() - i+1 < mxLen/2) break;
            int j = i, k = i;
            while(k+1 < s.size() && s[k+1] == s[k])k++;
            while(j-1 >=0 && s[j-1] == s[j]) j--;
            while(k+1 < s.size() && j-1 >=0 && s[k+1] == s[j-1] ){
                k++;
                j--;
            }
            cout << j <<" "<< k<<endl;
            int mx_len = k-j+1;
            if(mx_len > mxLen){
                mxLen = mx_len;
                min_start = j;
            }
        }
        return s.substr(min_start, mxLen);
    }
};
