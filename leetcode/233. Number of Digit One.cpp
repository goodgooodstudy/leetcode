class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;int a = 1, b =1;
        while(n>0){
            res+= (n+8)/10*a+ (n%10 == 1)*b;
            b += (n%10)*a;
            a = a*10;
            n = n/10;
        }
        return res;
        
    }
};


class Solution { //从右到左，每一位为1时候，有多少种可能。
public:
    int countDigitOne(int n) {
        int res = 0;
        for(long long i = 1; i <=n; i =i*10){
            int f = n/i, e = n%i;
            res += (f+8)/10 *i + (f%10 == 1)*(e+1);
        }
        return res;
        
    }
};
