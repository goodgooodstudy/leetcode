class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> maps;
        for(auto c : s){
            maps[c]++;
        }
        int oddmx = 0;
        bool odd = false;
        int total = 0;
        for(auto m : maps){
            if(m.second%2 != 0){
                total += m.second-1;
                odd =true;
            }
            else{
                total += m.second;
            }
        }
        if(odd)total += 1;
        return total;
    }
};
