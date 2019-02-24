class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for(int k = 1; k*k < 2*N; k++){
            if((2*N)%k != 0) continue;
            int x = 2*N/k -k -1;
            if(x%2 == 0){
                ans++;
            }
        }
        return ans;
        
    }
};
