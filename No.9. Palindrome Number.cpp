class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0) return false;
        int d = 1;
        int tmp = x;
        
        while(x/d >= 10){
            d = d * 10;
        }
        while(x > 0){
            int q = x / d;
            int p = x % 10;
            if(q != p) return false;
            x = x%d/10;
            d = d/100;
            
        }
        return true;
        
    }
};
