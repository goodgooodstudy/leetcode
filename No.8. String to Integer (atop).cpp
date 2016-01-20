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
