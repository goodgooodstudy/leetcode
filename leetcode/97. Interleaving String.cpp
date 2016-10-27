class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(),n3 = s3.size();
        if(n1+n2!=n3) return false;
        if(n1 == 0) return s2 == s3;
        if(n2 == 0) return s1 == s3;
        vector<vector<bool>> match(n1+1,vector<bool>(n2+1,false));
        match[0][0] = true;
        for(int i = 1; i < n1+1; i++) match[i][0] = (s1[i-1] == s3[i-1]) && match[i-1][0];
        for(int j = 1; j < n2+1; j++) match[0][j] = (s2[j-1] == s3[j-1]) && match[0][j-1];
        
        for(int i =1; i < n1+1; i++){
            for(int j = 1; j < n2+1; j++){
                match[i][j] = (s2[j-1] == s3[i+j-1] && match[i][j-1]) || (s1[i-1] == s3[i+j-1] && match[i-1][j]);
            }
        }
        return match[n1][n2];
        
        
    }
};
