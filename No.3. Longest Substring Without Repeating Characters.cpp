class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int i = 0,j = 1;
        int length = 1;
        while(j < s.size()){
            string sub = s.substr(i,j-i);
            int pos = sub.find(s.at(j));
            if(pos != -1){ //found
                if(length < j - i){
                    length = j-i;
                }
                i = i + pos + 1;
            }
            j = j + 1;
            
        }
        if(length < j-i) length  = j -i;
        return length;
        
    }
};

//hash table it runs faster than the below
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        vector<int> hash(256,-1);
        int length = 1;
        int start = 0;
        for (int i = 0; i < s.size(); i++){
            if(hash[s[i]] >= start){ //found
                start = hash[s[i]] + 1;
                
            }
            else{
                if (length < i-start+1){
                    length = i-start+1;
                }
            }
            hash[s[i]] = i;
            
        }
        return length;
        
    }
};
