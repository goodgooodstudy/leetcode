class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> maps1;
        unordered_map<char, char> maps2;

        for(int i = 0; i<s.size(); i++){
            if(maps1.count(s[i])||maps2.count(t[i])){ // 两个都要！！！
                if(t[i]!=maps1[s[i]]||s[i]!=maps2[t[i]]) return false;
            }
            else{
                cout << "ASD"<<endl;
                maps1[s[i]] = t[i];
                maps2[t[i]] = s[i];
            }
        }
        return true;
        
    }
};
