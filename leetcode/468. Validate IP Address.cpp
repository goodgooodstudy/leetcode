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
