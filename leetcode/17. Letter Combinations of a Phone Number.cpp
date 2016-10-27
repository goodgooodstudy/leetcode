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

//python
// class Solution:
//     # @return a list of strings, [s1, s2]
//     # @param {string} digits
//     # @return {string[]}
//     def letterCombinations(self, digits):
//         if '' == digits: return []
//         kvmaps = {
//             '2': 'abc',
//             '3': 'def',
//             '4': 'ghi',
//             '5': 'jkl',
//             '6': 'mno',
//             '7': 'pqrs',
//             '8': 'tuv',
//             '9': 'wxyz'
//         }
//         return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])
