class Solution {
public:
    string minWindow(string s, string t) {
        int begin = 0, end = 0, minLen = INT_MAX,counter = t.size(),head;
        vector<int> map(128,0);
        for(auto c:t) map[c]++;
        while(end < s.size()){
            if(map[s[end++]]-->0) counter--;
            while(counter == 0){
                if(end - begin < minLen){
                    minLen = end-begin;
                    head = begin;
                }
                if(map[s[begin++]]++ == 0) counter++;
            }
        }
        return minLen == INT_MAX? "": s.substr(head,minLen);
    }
};
