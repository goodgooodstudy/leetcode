class Solution {
public:
    bool isDigital(char tmp){
        if((tmp - '0' >=0) && (tmp - '0' <= 9)) return true;
        else return false;
    }
    
    int myAtoi(string str) {
        long long result = 0;
        int negative = 1;
        bool legal = 1;
        int i = 0;
        while(i<str.size() && str[i] == ' ') {
            i++;
        }
        if(i < str.size() && str[i] == '-' ){
            negative = -1;
            i++;
        }
        else if(i<str.size() && str[i] == '+'){
            negative = 1;
            i++;
        }
        
   
        for ( ;i<str.size();i++ ){
            if(!isDigital(str[i])) break;
            result = result* 10 + str[i]-'0';
            if(result*negative > INT_MAX ) return INT_MAX;
            if(result*negative < INT_MIN  ) return INT_MIN ;
            
        }
        result = negative*result;
        return (int)result;
        
    }
    
};


class Solution {
public:
    int myAtoi(string str) {
        if(str == "") return 0;
        long  rst = 0;
        int idx = 0;
        bool isNeg = false;
        while(idx < str.size() && str[idx] == ' ')idx++;
        if(str[idx] == '+'){
            isNeg = false;
            idx++;
        }
        else if(str[idx] == '-'){
            isNeg = true;
            idx++;
        }
        while(str[idx] >= '0' && str[idx] <= '9'){
            rst = rst*10 + str[idx]-'0';
            if(rst > INT_MAX && !isNeg) return INT_MAX;
            if(rst > long(INT_MAX)+1 && isNeg) return INT_MIN;
            idx++;
        }
        if(isNeg) rst = -rst;

        return rst;
        
    }
};
