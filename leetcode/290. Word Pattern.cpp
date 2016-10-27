class Solution {
public:

    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p2str;
        unordered_map<string,char>str2p;
        
        istringstream in(str);
        vector<string> words;
        string word;
        while(in >> word){
            words.push_back(word);
            
        }
        if(words.size()!=pattern.size()) return false;
        
        for(int i = 0; i < pattern.size(); i++){
            if(!p2str.count(pattern[i]) && !str2p.count(words[i])){
                p2str[pattern[i]] = words[i];
                str2p[words[i]]=pattern[i];
            }
            else{
                if(p2str[pattern[i]] != words[i] || str2p[words[i]] != pattern[i]){
                    return false;
                    
                } 
            }
        }
        return true;
    }
};
