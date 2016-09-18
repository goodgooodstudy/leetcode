class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        long long curNum = numerator, curDen = denominator;
        if(numerator == 0) return "0";
        if(denominator == 0) return res;
        if(numerator >0 && denominator >0 || (numerator < 0 && denominator < 0));
        else res+='-';
        if(numerator < 0) curNum = -curNum;
        if(denominator < 0) curDen = -curDen;
        
        if(curNum % curDen == 0){
            res += to_string(curNum/curDen);
            return res;
        }
        res += to_string(curNum/curDen)+".";
        curNum = curNum%curDen;
        unordered_map<int, int> mp;
        while(curNum){
            if(mp.count(curNum)){
                res.insert(mp[curNum],"(");
                res+=")";
                break;
                
            }
            mp[curNum] = res.size();

            curNum = 10*curNum;
            res+=to_string(curNum/curDen);
            curNum = curNum % curDen;
        }
       
        return res;
    }
};
