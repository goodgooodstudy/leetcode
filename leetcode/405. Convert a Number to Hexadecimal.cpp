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

class Solution {
public:
    string toHex(int num) {
        uint32_t n = num;
        if(n==0) return "0";
        string rst;
        while(n != 0){
            int cur = n%16;
            if(cur >=10){
                rst+='a'+cur-10;
            }
            else rst+='0'+cur;
            n = n/16;
        }
        reverse(rst.begin(), rst.end());
        return rst;

    }
};
