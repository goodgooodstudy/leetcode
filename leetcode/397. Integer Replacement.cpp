if n is even, n >>1;
if *01(or 11) -> *00(10) -> *0(1)->*
if *11 -> *100 ->*10->*1
class Solution {
public:
    int integerReplacement(int n) {
        int c = 0;
        if(n == INT_MAX) return 32; //!!n++  overflow
        while(n != 1){
            if((n&1) == 0){
                n = n>>1;
            }
            else if(n == 3 || ((n>>1) & 1) == 0){
                n--;
            }
            else{
                n++;
            }
            c++;
        }
        return c;
    }
};
