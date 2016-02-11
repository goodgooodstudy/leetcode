class Solution {
public:
    double myPow(double x, int n) {
        double results = 1;
        if(n == 0) return results;
        
        else if(n < 0){
            if(n == INT_MIN){
                results = myPow(x,INT_MAX)*x;
            }
            else{
                int index = -n;
                results = myPow(x,index);
            }
            results = 1/results;
        }
        else{
            if(n%2 == 0) {
            double tmp = myPow(x,n/2);
            results = tmp*tmp;
            }
            else{
                double tmp = myPow(x,(n-1)/2);
                results = tmp* tmp * x;
            }
        
        }
        
        return results;
        
    }
};
