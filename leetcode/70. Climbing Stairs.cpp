class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int n1 = 1, n2 = 2;
        int next = n1+n2;
        for(int i = 4; i<=n;i++){
            n1 = n2;
            n2 = next;
            next  = n1+n2;
        }
        
        return next;
    }
};
