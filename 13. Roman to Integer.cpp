class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['M'] = 1000;
        dict['D'] = 500;
        dict['C'] = 100;
        dict['L'] = 50;
        dict['X'] = 10;
        dict['V'] = 5;
        dict['I'] = 1;
        
        if (s.size() == 0) return 0;
        int ret= 0;
        for (int i = 0; i<s.size()-1; i++){
            if(dict[s[i]] < dict[s[i+1]]) 
                ret = ret - dict[s[i]];
            else
                ret = ret + dict[s[i]];
            
        }
        ret = ret + dict[s[s.size()-1]];
        return ret;
        
    }
    
};
