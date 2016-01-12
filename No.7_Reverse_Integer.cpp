

class Solution {
public:
    int reverse(int x) {
        int  result = 0;

        while(x != 0){
            if ((result > 0 &&result > (numeric_limits<int>::max() - x%10)/10) || (result < 0 && result < (numeric_limits<int>::min() - x%10)/10))
                return 0;
            result = result*10 + x%10;
            x = x/10;

        }
       
        return result;
        
    }
};
