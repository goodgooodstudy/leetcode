
class Solution {
public:
    bool isPowerOfThree(int n) {
        int power = 1;
        if (n == 1) return true;
        if (n%3 !=0) return false;  //if it is commented out, time will exceed....
        while(power < n){
            power =  power * 3;
        }
        if (power == n) return true;
        else return false;
        // return n>0?!(1162261467 % n):0;  //it works as well, but you need to calculate the max one of power 3




    }
};
