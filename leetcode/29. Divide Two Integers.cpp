class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; //overflow problem
        
        bool signNeg = (dividend<0)^(divisor<0);
        
        unsigned long dvd = abs((long)dividend);
        unsigned long dvs = abs((long)divisor);
        if(dvd < dvs) return 0;
        
        
        unsigned long ori_dvs = dvs;
        int step = 0;
        while(dvd > dvs){
            dvs = dvs <<1;
            step++;
        }
        unsigned long result = 0; ///unsigned!!!! long i = 1<<31; i->-2147483648
        while(dvd >= ori_dvs){
            if(dvd >= dvs){
                result += (unsigned long)1 << step;
                dvd = dvd - dvs; 
            }
            dvs = dvs >> 1;
            step --;
        }

        if(signNeg) result = -result;
        // if(result > INT_MAX) return INT_MAX; 
        // if(result < INT_MIN) return INT_MAX;//not happen, and it will make INT_MIN to (unsigned long) for comparision.....
        return result;
    }
};


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || dividend == INT_MIN && divisor ==-1)return INT_MAX;
        int sign = (dividend < 0) ^ (divisor < 0)?-1:1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);

        int step = 1, rst = 0;
        long long ori_dvs = dvs;
        while(dvd >= dvs){
            
            while(dvd >= dvs){
                dvd = dvd - dvs;
                rst = rst + step;
                dvs = dvs << 1;
                step = step << 1;
                
            }
        dvs = ori_dvs;
        step = 1;
        }
        return sign * rst;
        
        
        

        
    }
   
    
};
