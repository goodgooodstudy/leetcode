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
class Solution {
public:
    string countAndSay(int n){
        if(n == 0) return "";
        string res = "1";
        while(--n > 0){
            string tmp;
            for(int i = 0; i <res.size(); i++){
                int count = 1;
                while(i+1 < res.size() && res[i] == res[i+1]){
                    count ++;
                    i++;
                }
                tmp += to_string(count) + res[i];
            }
            res = tmp;
        }
        return res;

    
    }
  
};
