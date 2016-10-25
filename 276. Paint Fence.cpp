class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n == 1) return k;
        int same = k, diff = k*(k-1);
        for(int i = 3; i <= n; i++){
            int lst_diff = diff;
            diff = (same+lst_diff)*(k-1);
            same = lst_diff;
        }
        return same+diff;
        
        
    }
};
