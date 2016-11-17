class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int idx_w = 0;
        int idx_a = 0;
        bool alph = false;
        while(idx_a < abbr.size()){
            if(abbr[idx_a] <='z' && abbr[idx_a] >= 'a'){
                if(idx_w >= word.size()) return false;
                if(abbr[idx_a] != word[idx_w]) return false;
                idx_a++, idx_w++;
            }
            else{
                int num = 0;
                if(abbr[idx_a] == '0') return false;
                while(idx_a < abbr.size() && isdigit(abbr[idx_a])){
                    num = num*10 + abbr[idx_a++]-'0';
                }
                idx_w+=num;
            }
        }
        return idx_w == word.size();
    }
};
