class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0) return true;
        int start=0, end;
        int squre;
        end = num/2+1;
        while(start <= end){
            int mid = (start+end)/2;
            squre = mid * mid;
            if (mid > 0 &&mid*mid / mid != mid){ //overflow test
                end = mid -1;
            }
            else{
                if(squre == num) return true;
                else if(squre < num){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            
        }
        return false;
    }
};
