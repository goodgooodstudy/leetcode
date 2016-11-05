class Solution {
public:
    int reverse(int x) {
        int  result = 0;

        while(x != 0){

            if ((result >0 &&result > (numeric_limits<int>::max() - x%10)/10) || (result <0 &&result <(numeric_limits<int>::min() - x%10)/10))
                return 0;
            result = result*10 + x%10;
            x = x/10;
            
        }

        return result;
        
    }
};

class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if(x < 0) isNeg = true;
        long x_abs = abs(long(x));
        long rst = 0;
        while(x_abs > 0){
            rst = rst*10 + x_abs%10;
            x_abs = x_abs/10;
        }
        if(isNeg) rst = -rst;
        if(rst > INT_MAX) return 0;
        if(rst < -INT_MIN) return 0;
        return rst;
        
    }
};
