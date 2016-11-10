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

class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int i = 0, j = s.size()-1;
        while( i < j){
            while(i < j && vowels.find(s[i]) == string::npos) i++;
            while(i < j && vowels.find(s[j]) == string::npos) j--;
            if(i < j) swap(s[i++], s[j--]);
        }
        return s;
        
    }
};
