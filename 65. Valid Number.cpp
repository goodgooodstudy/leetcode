class Solution {
public:
    bool isNumber(string s) {
        //"1 1"is not valid, "0x11" is not valid, "." is not valid, "2e3.1" is not valid, "2e" is not valid,"1a" is not valid,"++1" is not valid
        int n = s.size();
        if(n == 0) return false;
        int i = 0;
        int count_num = 0,count_point = 0;
        while(s[i] == ' ') i++;
        if(s[i] == '+' || s[i] == '-') i++;
        while(isdigit(s[i]) || s[i] == '.') s[i++] == '.'?count_point++:count_num++;
        if(count_point > 1 || count_num < 1) return false;
        if(s[i] == 'e'){
            i++;
            count_num = 0;count_point = 0;
            if(s[i] == '+' || s[i] == '-') i++;
            while(isdigit(s[i]) || s[i] == '.') s[i++] == '.'?count_point++:count_num++;
            if(count_point > 0 || count_num < 1) return false;
        }
        while(s[i] == ' ') i++;
        return i == n;
    }
};
