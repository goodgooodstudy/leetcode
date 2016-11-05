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
class Solution {
public:
    bool isPalindrome(int x) {
        int len = 1;
        if(x < 0) return false;
        int tmpx = x;
        while(tmpx >= 10){
            len = len*10;
            tmpx = tmpx/10;
        }
        // len = len/10;
        tmpx = x;

        while(tmpx){
            int high = tmpx/len;
            int low = tmpx%10;
            if(high != low) return false;
            tmpx = tmpx - (tmpx/len)*len;
            tmpx = tmpx/10;
            len = len/100;

        }
        
        return true;
    }
};
