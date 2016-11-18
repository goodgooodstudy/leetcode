class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty()) return 0;
        int n = A.size();
        vector<unordered_map<int, int>> dp(n);
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
         if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;// do not ignore this step, it will help you save time & space to pass OJ.

                int dif = A[i]-A[j];
                dp[i][dif]+=1;
                if(dp[j].count(dif)){
                    dp[i][dif]+=dp[j][dif];
                    res += dp[j][dif]; //!!!
                }
            }
        }
        
        return res;
    }
};
