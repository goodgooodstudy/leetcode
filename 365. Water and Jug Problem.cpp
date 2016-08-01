class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return (x + y == z) || (x+y > z) && z % gcd(x,y) == 0;
    }
    int gcd(int a, int b){
        return a == 0?b:gcd(b%a,a);
    }
};
