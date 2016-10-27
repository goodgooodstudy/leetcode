class Solution {
public:
    // int addDigits(int num) {
    //     while(num>=10){
    //         int digit = 0;
    //         while(num >0){
    //             digit += num%10;
    //             num/=10;
    //         }
    //         num = digit;
    //     }
    //     return num;
        
    // }
    int addDigits(int num){
        if(num == 0) return 0;
        else if(num%9==0) return 9;
        else return num%9;
    }
};
