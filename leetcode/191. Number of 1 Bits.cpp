class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while(n >0){
            if(n&1 == 1) ones++;
            n = n>>1;
        }
        return ones;
        
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        while(n > 0){
            if(n&0x1) total += 1;
            n = n >> 1;
        }
        return total;
    }
};
