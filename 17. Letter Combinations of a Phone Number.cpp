class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> set;
        if(digits=="") return set;
        string dict[] = {" ", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string res;
        dfs(dict, digits, 0, set, res);
        return set;
        
        
    }
    void dfs(string dict[], string& digits, int deep, vector<string>& set,string& res){
        
        if(deep == digits.size()){
            set.push_back(res);
            return;
        }
        int digit = digits[deep++] - '0';
        if(digit <0 || digit > 9) return;
        

        for (int i = 0; i < dict[digit].size(); i++){
            res.push_back(dict[digit][i]);
            dfs(dict, digits, deep,set,res);
            res.pop_back();
        }
        return;
        
    }
};
