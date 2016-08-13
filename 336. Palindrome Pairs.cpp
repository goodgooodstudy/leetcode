class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); i++){
            string cur = words[i];
            reverse(cur.begin(), cur.end());
            dict[cur] = i;
        }
        
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                if(dict.count(left) && isPalindrome(right) && dict[left]!=i){
                    res.push_back({i,dict[left]});
                    if(j == 0) res.push_back({dict[left],i});
                }
                if(dict.count(right) && isPalindrome(left) && dict[right] != i){
                    res.push_back({dict[right],i});
                }
            }
        }
        return res;
        
        
        
    }
    bool isPalindrome(string s){
        int begin = 0, end = s.size()-1;
        while(begin < end){
            if(s[begin++]!=s[end--]) return false;
        }
        return true;
    }
};
