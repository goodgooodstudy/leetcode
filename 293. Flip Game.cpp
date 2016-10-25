class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for(int i = 1; i < s.size(); i++){
            string tmp = s;
            if(s[i] == s[i-1] && s[i] == '+'){
                tmp[i]=tmp[i-1]='-';
                res.push_back(tmp);
            }
        }
        return res;
        
    }
};
