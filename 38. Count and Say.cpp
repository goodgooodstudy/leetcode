class Solution {
public:
    string countAndSay(int n) {
        string res;
        if(n == 0)return res;
        res = "1";
        string next;
        while(--n){
            next = "";
            int i = 0;
            while(i<res.size()){
                int count = 0;
                int j = i;
                while(res[j] == res[i]){
                    count++;
                    j++;
                }
               next = next+to_string(count)+res[i];
                i = j;
            }
            res = next;
        }
        return res;
        
        
    }
};
