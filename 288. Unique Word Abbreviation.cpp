class ValidWordAbbr {
public:
    unordered_map<string, int> mp;
    unordered_map<string, int> cnt;
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto item: dictionary){
            if(!cnt.count(item)){
                mp[word2form(item)]++;
            } 
            cnt[item]++;

        }
        
    }

    bool isUnique(string word) {
        if(mp[word2form(word)] == 0) return true;
        if(mp[word2form(word)] == 1 && cnt.count(word)) return true;
        return false;

    }
    string word2form(string s){
        if(s.size()<=2) return s;
        string res;
        res = s[0]+to_string(s.size()-2)+s[s.size()-1];
        return res;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
