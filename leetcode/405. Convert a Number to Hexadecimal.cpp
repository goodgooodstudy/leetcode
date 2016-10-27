class Solution {
public:
    string toHex(int num) {
        string rst;
        if(num == 0) return "0";
        int count = 0;
        while(count <8&&num){
            int tmp = num&15;
            if(tmp < 10)rst.push_back('0'+tmp);
            else rst.push_back('a'+tmp-10);
            num = num>>4;
            count++;
        }
        reverse(rst.begin(),rst.end());
        return rst;
        
    }
};
