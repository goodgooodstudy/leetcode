class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k = k-1;
        while(k > 0){
            int steps = getStep(n, cur, cur+1);
            if(steps <= k){
                k-=steps;
                cur = cur+1;
            }
            else{
                k-=1;
                cur = cur*10;
            }
        }
        return cur;
    }
    int getStep(int n, long n1, long n2){
        int steps = 0;
        while(n1 <= n){
            steps += min(n2, (long)n+1)-n1;
            n1 = n1*10;
            n2 = n2*10;
        }
        return steps;
    }
};
