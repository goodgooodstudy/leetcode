class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> possible(n+1, false);
        possible[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j+1 < i; j++){
                if(wordDict.count(s.substr(j, i-j)) && possible[j]) {
                    possible[i] = true;
                    break;
                }
            }
        }
        return possible[n];
        
    }
};


class Solution {
private:
    set<int> idx;
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        
        // vector<bool> mark(s.size()+1, false); //len
        // mark[0] = true;
        // int i = 0; 
        // while(i <= s.size()){
        //     for(auto d : wordDict){
        //         if(s.substr(i,d.size()) == d){
        //             mark[i+d.size()] = true;
        //         }
        //     }
        //     i++;
        //     while(i<=s.size()&&mark[i] == false) {
        //         i++;
        //     }
        // }
        // return mark[s.size()];
        return helper(s, 0, wordDict);
        
    }
    bool helper(string& s, int pos, unordered_set<string>& wordDict){
        if(pos == s.size()) return true;
        if(idx.count(pos)) return false;
        for(int i = 1; i <= s.size()-pos; i++){
            string tmp = s.substr(pos, i);
            if(wordDict.count(tmp) && helper(s, pos+i, wordDict)) return true;
        }
        idx.insert(pos);
        return false;
    }
};
