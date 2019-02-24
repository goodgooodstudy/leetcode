class Solution {
public:
    vector<string> splitdot(string s){
        vector<string> res;
        stringstream ss(s);
        string cur;
        while(getline(ss, cur, '.')){
            res.push_back(cur);
        }
        return res;
    }
    bool valid4(string s){
        if(s.size() <= 0 || s.size() > 3) return false;
        if(s.size() == 1 && s[0] == '0') return true;
        if(s.size() > 1 && s[0] == '0') return false;
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] <'0' || s[i] > '9') return false;
            num = num*10 + s[i]-'0';
        }
        if(num > 255 || num < 0) return false;
        return true;
    }
    bool valid6(string s){
        if(s.size() <= 0 || s.size() > 4 ) return false;
  
        long long num = 0;
        for(int i = 0; i < s.size(); i++){
            num = num*16;
            if(s[i] >= '0' &&  s[i] <= '9') num += s[i]-'0';
            else if(s[i] >= 'a' && s[i] <= 'f'){
                num += s[i]-'a' + 10;
            }
            else if( s[i] >= 'A' && s[i] <= 'F'){
                num += s[i]-'A' + 10;
            }
            else return false;
            
        }
        if(num > 0xffff || num < 0) return false;
        return true;
        
    }
    vector<string> splitcom(string s){
        vector<string> res;
        stringstream ss(s);
        string cur;
        while(getline(ss, cur, ':')){
            res.push_back(cur);
        }
        return res;
    }
    string validIPAddress(string IP) {
        if(IP.find_first_of(".")!=string::npos){
            vector<string> p = splitdot(IP);
            if(p.size() != 4) return "Neither";
            for(string s : p){
                if(!valid4(s)) return "Neither";
            }
            if(IP.back() == '.') return "Neither";
            return "IPv4";
        }
        else if(IP.find_first_of(":") != string::npos){
            vector<string> p = splitcom(IP);
            cout << p.size()<<endl;
            if(p.size() != 8) return "Neither";
            for(string s : p){
                if(!valid6(s)) return "Neither";
            }
            if(IP.back() == ':') return "Neither";
            return "IPv6";
        }
        else return "Neither";
    }
};



class Solution {
private:
    const string validIPv6Chars = "0123456789abcdefABCDEF";
public:
    string validIPAddress(string IP) {
        if(validIP4(IP)) return "IPv4";
        if(validIP6(IP)) return "IPv6";
        return "Neither";
    }
    bool validIP4(string IP){
        vector<string> res;
        IP+=".";
        stringstream ss(IP);
        string cur;
        while(getline(ss, cur, '.')){
            res.push_back(cur);
        }
        if(res.size() != 4) return false;
        for(string num : res){
            if(num.size() < 1||num.size() > 1 && num[0] == '0') return false;
            if(num.size() > 3) return false;
            int n = 0;
            for(int i = 0; i < num.size(); i++){
                if(num[i] < '0' || num[i] > '9') return false;
                n = n*10 + (num[i]-'0');
            }
            if(n<0 || n >255) return false;
        }
        return true;
    }
    bool validIP6(string IP){
        vector<string> res;
        IP+=":";
        stringstream ss(IP);
        string cur;
        while(getline(ss, cur, ':')){
            res.push_back(cur);
        }
        if(res.size() != 8) return false;
        for(int i = 0; i < 8; i++){
            if(res[i].size()>4 || res[i].size()<1) return false;
            for(int j = 0; j < res[i].size(); j++){
                if(validIPv6Chars.find(res[i][j]) == string::npos){
                    return false;
                }
            }
        }
        return true;
    }
};
