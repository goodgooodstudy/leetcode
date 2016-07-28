class Solution {
public:
    void reverseWords(string &s) {
        string r;
        int j = s.size();
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ') j = i;
            else if(i==0||s[i-1] == ' '){
                if(!r.empty())r.append(" ");
                r.append(s.substr(i,j-i));
            }
        }
        s = r;

    }
};
