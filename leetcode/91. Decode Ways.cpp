class Solution {
public:
    int numDecodings(string s) {
        if(!s.size() || s.front()=='0') return 0;
        int r1=1,r2=1; //r1 s[i-1] 次数, r2 s[i-2]次数
        for(int i = 1; i< s.size(); i++){
            if(s[i] == '0') r1=0;
            
            if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6'){
                r1 = r1 + r2;
                r2 = r1 - r2;
            }
            else{
                r2 = r1;
            }
        }
        return r1;
    }
};


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> len(n, 0);
        if(n==0) return 0;
        if(s[0]<'1' || s[0] > '9') return 0;
        if(s[0] >='1' && s[0] <='9')len[0] = 1;
        if(n == 1) return len[0];
        if(s[1] >='1' && s[1] <='9')len[1] = 1;
        if(isValid(s[0], s[1])) len[1] = len[1] + 1;
        
        for(int i = 2; i < n; i++){
            if(s[i] >='1' && s[i] <='9')len[i] = len[i-1];
            if(isValid(s[i-1], s[i])) len[i] += len[i-2];
        }
        return len[n-1];
        
        
    }
    bool isValid(char n1, char n2){
        if(n1=='1' || n1 == '2' && n2 <='6') return true;
        else return false;
    }
};
