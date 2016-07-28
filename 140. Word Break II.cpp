class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        vector<string> cur;
        vector<bool> possible(s.size()+1, true);
        dfs(s,0,wordDict,res,cur,possible);
        return res;
        
        
    }
    void dfs(string& s, int start, unordered_set<string>& wordDict, vector<string>& res, vector<string>& cur,vector<bool>& possible){
        if(start == s.size()&&cur.size()>0){
            string tmp = cur[0];
            for(int i = 1; i < cur.size();i++){
                tmp.append(" "+cur[i]);
            }
            res.push_back(tmp);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(wordDict.count(s.substr(start,i-start+1)) && possible[i+1]){
                cur.push_back(s.substr(start,i-start+1));
                int before = res.size();
                dfs(s, i+1, wordDict, res, cur,possible);
                if(res.size() == before) possible[i+1] = false;
                cur.pop_back();
            }
        }
    }
};

// 高级的做法
class Solution {
private: unordered_map<string, vector<string>> mp;
        vector<string> combine(vector<string> prev, string word){
            for(int i = 0 ; i<prev.size(); i++){
                prev[i].append(" "+word);
            }
            return prev;
        } 
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(mp.count(s)) return mp[s];
        vector<string> res;
        if(wordDict.count(s)) res.push_back(s);
        for(int i = 1; i < s.size(); i++){
            string word = s.substr(i);
            if(wordDict.count(word)){
                string rem = s.substr(0,i);
                vector<string> prev = combine(wordBreak(rem, wordDict),word);
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        mp[s] = res;
        return res;
        
        
    }
   
};
