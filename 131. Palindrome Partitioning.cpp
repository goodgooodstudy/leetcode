class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> rst;
        vector<string> cur;
        DFS(s,0,rst,cur);
        return rst;
    }
    void DFS(string& s, int start,vector<vector<string>>& rst, vector<string>& cur){
        if(start == s.size()){
            rst.push_back(cur);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start,i)){
                cur.push_back(s.substr(start, i-start+1));
                DFS(s,i+1,rst,cur);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start]!=s[end]) return false;
            start++;
            end --;
        }
        return true;
    }
};




dp judge ispal
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> rst;
        vector<string> cur;
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n,false));

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                isPal[i][j] = (s[i] == s[j]) &&(j-i<=2||isPal[i+1][j-1]); 

            }
        }
        DFS(s,0,isPal,rst,cur);
        return rst;
    }
    void DFS(string& s, int start, vector<vector<bool>>& isPal, vector<vector<string>>& rst, vector<string>& cur ){
        if(start == s.size()){
            rst.push_back(cur);
            return;
        }
        for(int i = start; i < s.size();i++){
            if(isPal[start][i]){
                cur.push_back(s.substr(start,i-start+1));
                DFS(s,i+1,isPal,rst,cur);
                cur.pop_back();
            }
        }
    }

};
