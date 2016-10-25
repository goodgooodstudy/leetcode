class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string cur = "";
        backtracking(res, cur,0,word, 0);
        return res;
        
    }
    
    void backtracking(vector<string>& res, string cur, int pos, string& word, int num){
        if(pos == word.size()){
            if(num > 0){
                cur += to_string(num);
            }
            res.push_back(cur);

        }
        else{
            backtracking(res, cur, pos+1, word, num+1);
            backtracking(res, cur+(num > 0 ? to_string(num) : "") + word.substr(pos,1),pos+1,word,0);
        }
        
        
    } 
};
