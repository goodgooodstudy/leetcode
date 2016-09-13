class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(char tmp : s) c ^= tmp;
        for(char tmp : t) c ^= tmp;
        return c;
        
    }
};
