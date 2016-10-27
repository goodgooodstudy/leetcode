class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (!(n & (n-1))); //&优先级低于== n&(n-1) == 0 有问题
        // return (n&(n-1)) == 0?true:false; //n>0 判断
    }
};
