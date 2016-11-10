class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return -1;
        long l = 0, r = x/2+1;
        while(l < r){
            long mid = l + (r-l)/2+1; // 因为mid*mid < x l 是符合条件的，但是又不能死循环，所以向右面靠。。
            if(mid * mid == x) return mid;
            else if(mid*mid < x){
                l = mid;
            }
            else{
                r = mid-1;
            }
        }
    
        return l;
    }
};


class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int start=0, end;
        int squre;
        end = x/2+1;
        while(start <= end){
            int mid = (start+end)/2;
            squre = mid * mid;
            if (mid > 0 &&mid*mid / mid != mid){ //overflow test
                end = mid -1;
            }
            else{
                if(squre == x) return mid;
                else if(squre < x){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            
        }
        return (start+end)/2;
    }
};
