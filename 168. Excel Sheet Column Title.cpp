class Solution {
public:
    string convertToTitle(int n) {
        if(n<1) return NULL;
        string s;
        while(n>0){
            int i = (--n)%26;
            s.push_back('A'+i);
            n = n/26;

        }
        reverse(s.begin(),s.end());
        return s;
        
    }
};
