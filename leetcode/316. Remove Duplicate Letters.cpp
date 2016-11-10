class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0);
        for(char a: s) cnt[a-'a']++;
        vector<bool> visited(26,false);
        stack<char> index;
        
        for(int i = 0; i < s.size(); i++){
            
            cnt[s[i] - 'a']--;
            if(visited[s[i]-'a']) continue;
            while(!index.empty() && index.top() >s[i] && cnt[index.top()-'a']){
                visited[index.top()-'a'] = false;
                index.pop();
            }
            index.push(s[i]);
            visited[s[i]-'a'] = true;
            
        }
        
        string res="";
        while(!index.empty()){
            res=index.top()+res;
            index.pop();

        } 
        return res;
        
    }
};

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // string vector mimic stack and keeps monotically increasing
        string rst;
        vector<bool> visited(26, false);
        vector<int> cnt(26, 0);
        for(char c : s) cnt[c-'a']++;
        for(char c : s){
            cnt[c-'a']--;
            if(visited[c-'a']) continue;
            while(!rst.empty() && c < rst.back() && cnt[rst.back()-'a'] > 0){
                visited[rst.back()-'a'] = false;
                rst.pop_back();
            }
            visited[c-'a'] = true;
            rst += c;
        }
        return rst;
        
    }
};
