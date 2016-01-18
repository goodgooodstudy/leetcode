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
