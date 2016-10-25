class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int j = -1;
        int mx = 0;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            while(mp.size() > 2){
                if(--mp[s[++j]] == 0)mp.erase(s[j]);
            }
            mx = max(mx, i-j);
        }
        return mx;
    }
};
