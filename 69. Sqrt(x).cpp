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
