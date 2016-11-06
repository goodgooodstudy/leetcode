class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> rst;
        unordered_map<string, int> cnt;
        for(int i = 0; i <= (int)s.size()-10; i++){ ///!!!!(int)s.size()
            string cur = s.substr(i, 10);
            cnt[cur]++;
            if(cnt[cur] == 2) rst.push_back(cur);
        }
        return rst;
        
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> maps;
        vector<string> res;
        for(int i = 10; i <= s.size(); i++){
            string cur = s.substr(i-10,10);
            if(maps.count(cur)&&maps[cur] ==1){
                res.push_back(cur);
                maps[cur]++;
            }
            else{
                maps[cur] ++;
            }
        }
        return res;
        
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> maps;
        vector<string> res;
        for(int i = 10; i <= s.size(); i++){
            string cur = s.substr(i-10,10);
            int code = encode(cur);
            if(maps.count(code)&&maps[code] ==1){
                res.push_back(cur);
                maps[code]++;
            }
            else{
                maps[code] ++;
            }
        }
        return res;
        
    }
    int encode(string s){
        int res=0;
        for(int i = 0; i < 10; i++){
            res = res<<2;
            switch (s[i]){
                case 'A':res+=0;break;
                case 'C':res+=1;break;
                case 'G':res+=2;break;
                case 'T':res+=3;break;
            }
        }
        return res;
    }
};
