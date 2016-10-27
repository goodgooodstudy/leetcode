class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int l = 0, r= s.size()-1;
        while(l<r){
            if(vowels.find(s[l]) == string::npos)l++;
            else if(vowels.find(s[r]) == string::npos)r--;
            else swap(s[l++],s[r--]);
        }
        return s;
        
    }
};
