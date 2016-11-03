/**
* @Author: lcy
* @Date:   2016-09-03T12:50:54-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



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

class Solution {
public:
    bool isNumber(string s) {
        enum InputType{
            INVALID,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXPONENT,
        };
        int transferTable[][6] ={
            -1,0,3,1,2,-1,
            -1,8,-1,1,4,5,
            -1,-1,-1,4,-1,-1,
            -1,-1,-1,1,2,-1,
            -1,8,-1,4,-1,5,
            -1,-1,6,7,-1,-1,
            -1,-1,-1,7,-1,-1,
            -1,8,-1,7,-1,-1,
            -1,8,-1,-1,-1,-1,
        };
        int state = 0;
        for(int i = 0; i < s.size(); i++){
            InputType input = INVALID;
            if(s[i] == ' ') input = SPACE;
            else if(s[i] == '+' || s[i] == '-') input = SIGN;
            else if(s[i] == '.') input = DOT;
            else if(s[i]>='0' && s[i] <= '9') input = DIGIT;
            else if(s[i] == 'e' || s[i] == 'E') input = EXPONENT;
            state = transferTable[state][input];
            if(state == -1) return false;
        }
        return state == 1 || state == 8 || state == 7 || state == 4;
    }
};
