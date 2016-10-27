class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        long long fives = 5;
        while(n/fives>0){
            sum += n/fives;
            fives *=5;
        }
        return sum;
    }
};
