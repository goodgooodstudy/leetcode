class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odd = 0, count[256] = {0};
        for(auto c : s){
            count[c] ++;
            if(count[c]%2 != 0) odd++;
            else odd--;
        }
        return odd <=1 ? true:false;
        
    }
};
