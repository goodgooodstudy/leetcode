class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sum = 0;
        for(int j = 0; j<32; j++){
            if(n&1 == 1){
                sum = (sum <<1) + 1;
            }
            else{
                sum = sum <<1;
            }
            n = n>>1;
            // uint32_t i = n%2;
            // sum = sum*2 + i;
            // n = n/2;
         
        }
        return sum;
        
    }
};
