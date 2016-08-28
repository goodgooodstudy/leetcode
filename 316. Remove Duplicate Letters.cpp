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
