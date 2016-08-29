class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> visited;
        queue<string> q;
        vector<string> res;
        bool found = false;
        
        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            if(isValid(cur)){
                res.push_back(cur);
                found = true;
            }
            else if(found == false){
                for(int i = 0; i < cur.size(); i++){
                    // string tmp = cur.substr(0,i) + cur.substr(i+1);
                    if(cur[i] == '(' || cur[i] == ')'){
                        string tmp = cur.substr(0,i) + cur.substr(i+1);
                        if(!visited.count(tmp)){
                            q.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }
        }
        return res;
        
        
    }
    bool isValid(string s){
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') cnt++;
            if(s[i] == ')'){
                if(cnt == 0) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
};
