class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() <4 || s.size() > 12) return res;
        
        for(int i = 1; i<4; i++){
            string first = s.substr(0,i);
            if(!isvalid(first)) continue;
            for(int j = 1; i+j < s.size() && j<4; j++){
                string second = s.substr(i,j);
                if(!isvalid(second)) continue;
                for(int k = 1; i+j+k < s.size() && k<4; k++ ){
                    string third = s.substr(i+j,k);
                    string forth = s.substr(i+j+k);
                    if(isvalid(third) && isvalid(forth)){
                        string tmp =first+'.'+second+'.'+third+'.'+forth;
                        res.push_back(tmp);
                    }
                }
                
            }
        
            
        }
        return res;
        
    }
    bool isvalid(string s){
        if (s.size() >1 && s[0] == '0') return false;
        if(stoi(s) >=0 && stoi(s) <=255)
            return true;
        else
            return false;
    
    }
};
