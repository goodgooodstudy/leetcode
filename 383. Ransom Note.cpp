class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> cnt;
        for(auto c : magazine)cnt[c]++;
        for(auto c : ransomNote){
            if(cnt[c] > 0){
                cnt[c]--;
            }
            else return false;
        }
        return true;
        
    }
};
